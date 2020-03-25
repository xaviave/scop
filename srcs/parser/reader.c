/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/25 20:25:31 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static t_list_parser	*open_file(int fd, int obj_index, t_parser *parser
	, short parsing_type)
{
	char				*line;
	t_list_parser		*list;

    list = NULL;
	ft_printf("Opening file: %s\n", parser->args[obj_index + 1]);
	while(get_next_line(fd, &line) > 0)
	{
		if (line && ft_strlen(line) > 1)
        {
            if (check_raw_data(line, parsing_type))
                add_list_parser(&list, line);
			else
			{
				ft_printf("\n%s\n", line);
                handle_error_parser("Error in line");
			}
        }
        ft_strdel(&line);
    }
	if (list == NULL || !list_parser_len(&list))
		handle_error_parser("File is empty.");
	return list;
}

static t_list_parser	*reader(t_parser *parser, char *file, int index,
	short parsing_type)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		handle_error_parser("Error while opening file.");
	return (open_file(fd, index - 1, parser, parsing_type));
}

void					reader_obj(t_parser *parser)
{
	int					i;
	t_list_parser		*list;

	i = 0;
	while (++i < parser->nb_args + 1)
	{
		list = NULL;
		list = reader(parser, parser->args[i], i, P_OBJ);
		ft_printf("Parsing file: %s\n", parser->args[i]);
		ft_printf("reader_obj %p\n", &list);
		init_obj(&parser->obj[i]);
		if (!list_parser_to_obj(&parser->obj[i], list))
			handle_error_parser("Error during parsing.");
	}
}