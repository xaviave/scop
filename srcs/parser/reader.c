/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 19:07:41 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static t_list_parser	*open_file(int fd, t_parser_option *opt)
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
                add_list_parser(&list, line, opt);
			else
			{
				ft_printf("\n%s\n", line);
                handle_error_parser("Error in line");
			}
        }
        ft_strdel(&line);
    }
	if (list == NULL || !opt->list_parser_len)
		handle_error_parser("File is empty.");
	return (list);
}

static t_list_parser	*reader(t_parser_option *opt)
{
	int fd;

	if ((fd = open(opt->file, O_RDONLY)) == -1)
		handle_error_parser("Error while opening file.");
	return (open_file(fd, opt));
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
		list = reader(&opt);
		ft_printf("Parsing file: %s\n", parser->args[i + 1]);
		init_obj(&parser->obj[i], &opt, i);
		if (!list_parser_to_obj(&parser->obj[i], list))
			handle_error_parser("Error during parsing obj.");
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
	{
		if (parser->obj[i].mtllib)
		{
			tmp = parser->obj[i].mtllib;
			parser->obj[i].mtllib = create_path(parser->path[i], parser->obj[i].mtllib);
			ft_strdel(&tmp);
			init_parser_option(&opt, parser->obj[i].mtllib, i, P_MTL);
			list = reader(&opt);
			parser->obj[i].mtl_id = i;
			ft_printf("Parsing file: %s\n", parser->obj[i].mtllib);
			init_mtl(&parser->mtl[i], i);
			if (!list_parser_to_mtl(&parser->mtl[i], list))
				handle_error_parser("Error during parsing mtl.");
		}
	}
}
