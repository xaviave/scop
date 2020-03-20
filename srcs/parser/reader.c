/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 21:49:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 1;
	err = (obj->len_faces) ? 1 : 0;
	err = (err && obj->len_groups) ? 1 : 0;
	err = (err && obj->len_lines) ? 1 : 0;
	err = (err && obj->len_normals) ? 1 : 0;
	err = (err && obj->len_objects) ? 1 : 0;
	err = (err && obj->len_space_vertexes) ? 1 : 0;
	err = (err && obj->len_textures) ? 1 : 0;
	err = (err && obj->len_vertexes > 2) ? 1 : 0;
	return (err);
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	int				id;
	short			err;
	void			(*f[7])(t_obj *, char *, int);
	t_list_parser	*tmp;

	id = 0;
	err = 0;
	tmp = list;
	init_ptr(f);
	init_obj(obj);
	while (tmp->next)
	{
		if (err <= tmp->id || err < 4)
		{
			err = tmp->id;
			f[tmp->id](obj, tmp->data, id);
		}
		tmp = list->next;
		free(list->data);
		free(list);
		id++;
	}
	return (check_obj(obj));
}

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	int				i;
	char			*line;
	t_list_parser	*list;

	i = 0;
	list = NULL;
	ft_printf("Opening file: %s\n", parser->args[obj_index]);
	while(get_next_line(fd, &line))
	{
		ft_printf("|%s|\t", line);
		if (line && ft_strlen(line) && ft_strchr(line, '#'))
			add_list_parser(&list, line);			
		else
			if (line)
				free(line);
	}
	if (list == NULL || !list_parser_len(&list))
		handle_error_parser("File is empty");
	ft_printf("Parsing file: %s\n", parser->args[obj_index]);
	if (list_parser_to_obj(&parser->obj[obj_index], list))
		handle_error_parser("Error durring Parsing");
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
	while (++i < parser->nb_args + 1)
	{
		fd = open(parser->args[i], O_RDONLY);
		open_file(fd, i, parser);
	}
}
