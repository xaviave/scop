/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/21 22:38:24 by xamartin         ###   ########lyon.fr   */
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
	err = (err && obj->len_lines) ? 1 : 0;
	err = (err && obj->len_vertexes > 2) ? 1 : 0;
	ft_printf("%d %d %d %d %d %d %d %d\n", obj->len_faces,  obj->len_groups,  obj->len_lines,  obj->len_normals,  obj->len_objects,  obj->len_space_vertexes,  obj->len_textures, obj->len_vertexes);
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
			parser_g(obj, tmp->data, id, tmp->next->id, len_list_parser_id(tmp, tmp->next->id));
		else if (tmp->id == 8)
			parser_o(obj, tmp->data, id, tmp->next->id, len_list_parser_id(tmp, tmp->next->id));
		tmp = tmp->next;
		id++;
	}
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	short			type;
	void			(*f[7])(t_obj *, char *);
	t_list_parser	*tmp;

	type = -1;
	init_ptr(f);
	init_obj_ptr(obj, list);
	define_groups_and_objects(obj, list);
	while (list->next)
	{
		if (list->id < 6 && type <= list->id)
			type = list->id;
		if (list->id < 7 && type == list->id)
			f[list->id](obj, list->data);
		ft_printf("type = %d\t", type);
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
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
				add_list_parser(&list, line);
			else
				handle_error_parser("Error in line");
		}
		else
			free(line);
	}
	if (list == NULL || !list_parser_len(&list))
		handle_error_parser("File is empty");
	ft_printf("Parsing file: %s\n", parser->args[obj_index + 1]);
	if (!list_parser_to_obj(&parser->obj[obj_index], list))
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