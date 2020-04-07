/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:25:03 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_list_parser	*open_file(int fd, t_parser_option *opt, t_addr **addr)
{
	char				*line;
	t_list_parser		*list;

    list = NULL;
	ft_printf("Opening file: %s\n", opt->file);
	while (get_next_line(fd, &line) > 0)
	{
		if (line && (opt->data_len = ft_strlen(line)) > 1)
        {
            if (check_raw_data(line, opt))
                add_list_parser(&list, line, opt, addr);
			else
			{
				ft_printf("\n%s\n", line);
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
		ft_printf("Parsing file: %s\n", parser->args[i + 1]);
		init_obj(&parser->obj[i], &opt, i, parser->nb_args, &parser->addr);
		if (!list_parser_to_obj(&parser->obj[i], list, &parser->addr))
			handle_error_parser("Error during parsing obj.", &parser->addr);
	}
}


void					reader_mtl(t_parser *parser)
{
	int					i;
	char				*tmp;
	t_parser_option		opt;
	t_list_parser		*list;

	i = -1;
	while (++i < parser->nb_args)
		if (parser->obj[i].mtllib)
		{
			tmp = parser->obj[i].mtllib;
			if (!(parser->obj[i].mtllib = create_path(parser->path[i], parser->obj[i].mtllib)))
            {
			    ft_strdel(&tmp);
                handle_error_parser("Error during memory allocation.", &parser->addr);
            }
			ft_strdel(&tmp);
			init_parser_option(&opt, parser->obj[i].mtllib, i, P_MTL);
			list = reader(&opt, &parser->addr);
			parser->obj[i].mtl_id = i;
			ft_printf("Parsing file: %s\n", parser->obj[i].mtllib);
			init_mtl(&parser->mtl[i], i, parser->nb_args);
			if (!list_parser_to_mtl(&parser->mtl[i], list, &parser->addr))
				handle_error_parser("Error during parsing mtl.", &parser->addr);
		}
}
