/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:36:04 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 17:48:00 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_list_parser	*open_file(int fd, t_parser_option *opt, t_addr **addr)
{
	char				*line;
	t_list_parser		*list;

	list = NULL;
	printf("Opening file: %s\n", opt->file);
	while (get_next_line(fd, &line) > 0)
	{
		if (line && (opt->data_len = ft_strlen(line)) > 1)
		{
			if (check_raw_data(line, opt))
				add_list_parser(&list, line, opt, addr);
			else
			{
				printf("\n%s\n", line);
				ft_strdel(&line);
				handle_error_parser("Error in line.", addr);
			}
		}
		ft_strdel(&line);
	}
	close(fd);
	if (list == NULL || !opt->list_parser_len)
		handle_error_parser("File is empty.", addr);
	return (list);
}

static t_list_parser	*reader(t_parser_option *opt, t_addr **addr)
{
	int fd;

	if ((fd = open(opt->file, O_RDONLY)) == -1)
		handle_error_parser("Error while opening file.", addr);
	return (open_file(fd, opt, addr));
}

void					reader_obj(t_parser *parser)
{
	int					i;
	t_parser_option		opt;
	t_list_parser		*list;

	i = -1;
	while (++i < parser->nb_args)
	{
		init_parser_option(&opt, parser->args[i + 1], i, P_OBJ);
		list = reader(&opt, &parser->addr);
		init_obj(&parser->obj[i], &opt, i, parser->nb_args, &parser->addr);
		if (!list_parser_to_obj(&parser->obj[i], list, &parser->addr))
			handle_error_parser("Error during parsing obj.", &parser->addr);
	}
}

static void				get_path_mtllib(t_parser *parser)
{
	char				*tmp;

	tmp = parser->obj[i].mtllib;
	if (!(parser->obj[i].mtllib = create_path(parser->path[i],
		parser->obj[i].mtllib)))
	{
		ft_strdel(&tmp);
		handle_error_parser("Error during memory allocation.", &parser->addr);
	}
	ft_strdel(&tmp);
}

void					reader_mtl(t_parser *parser)
{
	int					i;
	int					index;
	char				*tmp;
	t_parser_option		opt;
	t_list_parser		*list;

	i = -1;
	index = 0;
	while (++i < parser->nb_args)
		if (parser->obj[i].mtllib)
		{
			get_path_mtllib(parser);
			init_parser_option(&opt, parser->obj[i].mtllib, i, P_MTL);
			list = reader(&opt, &parser->addr);
			parser->obj[i].mtl_id = i;
			printf("Parsing file: %s\n", parser->obj[i].mtllib);
			init_mtl(&parser->mtl[index], i, parser, count_group_mtl(list));
			if (!list_parser_to_mtl(&parser->mtl[index], list, &parser->addr))
				handle_error_parser("Error during parsing mtl.", &parser->addr);
			index++;
		}
}
