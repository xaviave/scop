/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/26 11:45:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static t_list_parser	*open_file(int fd, t_parser *parser,
	t_parser_option *opt)
{
	char				*line;
	t_list_parser		*list;

    list = NULL;
	ft_printf("Opening file: %s\n", parser->args[opt->index + 1]);
	while (get_next_line(fd, &line) > 0)
	{
		if (line && line[0] != '#' && (opt->data_len = ft_strlen(line)) > 1)
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

static t_list_parser	*reader(t_parser *parser, t_parser_option *opt)
{
	int fd;

	if ((fd = open(opt->file, O_RDONLY)) == -1)
		handle_error_parser("Error while opening file.");
	return (open_file(fd, parser, opt));
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
		list = reader(parser, &opt);
		ft_printf("Parsing file: %s\n", parser->args[i + 1]);
		init_obj(&parser->obj[i], &opt);
		if (!list_parser_to_obj(&parser->obj[i], list))
			handle_error_parser("Error during parsing obj.");
	}
}

void					reader_mtl(t_parser *parser)
{
	int					i;
	t_list_parser		*list;

	i = -1;
	// NEED TO INIT TE NUMBER OF MTL FILE
	// MTL FILE IS OPTIONNAL
	while (++i < parser->nb_args)
	{
		if (parser->obj[i].mtllib)
		{
			list = NULL;
			// list = reader(parser, parser->obj[i].mtllib, i, P_MTL);
			ft_printf("Parsing file: %s\n", parser->obj[i].mtllib);
			init_mtl(&parser->mtl[i]);
			// UPDATE THE OBJ WITH THE ID OF THE MTL
			if (!list_parser_to_mtl(&parser->mtl[i], list))
				handle_error_parser("Error during parsing mtl.");
		}
	}
}