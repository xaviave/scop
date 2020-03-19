/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/19 21:08:35 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void			list_parser_to_obj(t_parser *parser, t_list_parser *list)
{
	
}

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	int				i;
	char			*line;
	t_list_parser	*list;

	i = 0;
	ft_printf("Parsing file: %s\n", parser->args[obj_index]);
	while(get_next_line(fd, &line))
	{
		if (ft_strlen(line) && ft_strchr(ft_strtrim(line), '#'))
			ft_printf("ENTER HERE FOR COMMENT\n");
		add_list_parser(&list, line);
		free(line);
	}
	list_parser_to_obj(parser, list);
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
