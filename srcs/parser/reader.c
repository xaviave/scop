/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 15:57:06 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	char			*line;
	t_list_parser	*list;

	ft_printf("name of args = %s\n", parser->args[obj_index]);
	while(get_next_line(fd, &line))
	{
//		add_list_parser(&list, line);
		free(line);
	}
	ft_printf("NEED TO FREE T_LIST_PARSER - reader.c l.26");
}

/*
**	Allow multiple file opening
*/
void				reader(t_parser *parser)
{
	int				i;
	int				fd;
	
	i = 0;
	while (++i < parser->nb_args)
	{
		fd = open(parser->args[i], O_RDONLY);
		open_file(fd, i, parser);
	}
}
