/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/21 17:55:50 by xamartin         ###   ########lyon.fr   */
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

static void			define_groups_and_objects(t_obj *obj, t_list_parser *list)
{
	int				id;
	t_list_parser	*tmp;

	id = 0;
	tmp = list;
	while (tmp->next)
	{
		if (tmp->id == 7)
			parser_g(obj, tmp->data, id, len_list_parser_id(tmp, tmp->next->id));
		else if (tmp->id == 8)
			parser_o(obj, tmp->data, id, len_list_parser_id(tmp, tmp->next->id));
		tmp = tmp->next;
		id++;
	}
	ft_printf("id = %d\n", id);
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	int				id;
	short			err;
	void			(*f[7])(t_obj *, char *, int);
	t_list_parser	*tmp;

	id = -1;
	err = -1;
	tmp = list;
	init_ptr(f);
	define_groups_and_objects(obj, list);
	exit(0);
	while (tmp->next)
	{
		if (tmp->id < 6 && err <= tmp->id)
		{
			id = -1;
			err = tmp->id;
		}
		if (tmp->id < 7 && err == tmp->id)
			f[tmp->id](obj, tmp->data, ++id);
		tmp = list->next;
		free(list->data);
		free(list);
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
	init_obj(&parser->obj[obj_index]);
	ft_printf("Opening file: %s\tobj address %p\n", parser->args[obj_index + 1], &parser->obj[obj_index]);
	ft_printf("CRASH WHEN FILE IS EMPTY\n\n");
	while(get_next_line(fd, &line) > 0)
	{
		if (line && ft_strlen(line) && !ft_strchr(line, '#'))
		{
			if (check_raw_data(line))
				add_list_parser(&parser->obj[obj_index], &list, line);
			else
				handle_error_parser("Error in line");
		}
		else
			free(line);
	}
	if (list == NULL || !list_parser_len(&list))
		handle_error_parser("File is empty");
	ft_printf("Parsing file: %s\n", parser->args[obj_index + 1]);
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
		open_file(fd, i - 1, parser);
	}
}