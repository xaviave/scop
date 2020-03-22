/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 15:39:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static void			print_obj(t_obj *obj)
{
	int i = -1;
	
	ft_printf("%d %d %d %d %d %d %d %d\n", obj->len_faces,  obj->len_groups,  obj->len_lines,  obj->len_normals,  obj->len_objects, obj->len_textures, obj->len_vertexes);
	ft_printf("\n--------------------------------------------------\nvertexes:\n");
	if (obj->len_vertexes)
		while (++i < obj->len_vertexes)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f | w = %10f | %p\n", obj->vertexes[i].id, obj->vertexes[i].x, obj->vertexes[i].y, obj->vertexes[i].z, obj->vertexes[i].w, &obj->vertexes[i]);
	ft_printf("\n--------------------------------------------------\ntextures:\n");
	if (obj->len_textures)
		while (++i < obj->len_textures)
			dprintf(1, "id = %4d | u = %10f | v = %10f | w = %10f\n", obj->textures[i].id, obj->textures[i].u, obj->textures[i].v, obj->textures[i].w);
	ft_printf("\n--------------------------------------------------\nnormals:\n");
	if (obj->len_normals)
		while (++i < obj->len_normals)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f\n", obj->normals[i].id, obj->normals[i].x, obj->normals[i].y, obj->normals[i].z);
	ft_printf("\n--------------------------------------------------\ngroups:\n");
	if (obj->len_groups)
		while (++i < obj->len_groups)
			dprintf(1, "id = %4d | name = %10s | type = %d | first_id = %3d | nb_entity = %3d\n", obj->groups[i].id, obj->groups[i].name, obj->groups[i].type, obj->groups[i].first_entity, obj->groups[i].nb_entity);
	ft_printf("\n--------------------------------------------------\nobjects:\n");
	if (obj->len_objects)
		while (++i < obj->len_objects)
			dprintf(1, "id = %4d | name = %10s | type = %d | first_id = %3d | nb_entity = %3d\n", obj->objects[i].id, obj->objects[i].name, obj->objects[i].type, obj->objects[i].first_entity, obj->objects[i].nb_entity);
	ft_printf("\n--------------------------------------------------\nlines:\n");
	if (obj->len_lines)
		while (++i < obj->len_lines)
			dprintf(1, "id = %4d\n", obj->lines[i].id);
	ft_printf("\n--------------------------------------------------\nfaces:\n");
	if (obj->len_faces)
		while (++i < obj->len_faces)
			dprintf(1, "id = %4d\n", obj->faces[i].id);

}

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 1;
	err = (obj->len_faces) ? 1 : 0;
	err = (err && obj->len_lines) ? 1 : 0;
	err = (err && obj->len_vertexes > 2) ? 1 : 0;
	print_obj(obj);
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
		if (tmp->id == 6)
			parser_g(obj, tmp->data, id, tmp->next->id, len_list_parser_id(tmp, tmp->next->id));
		else if (tmp->id == 7)
			parser_o(obj, tmp->data, id, tmp->next->id, len_list_parser_id(tmp, tmp->next->id));
		tmp = tmp->next;
		id++;
	}
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	short			type;
	void			(*f[6])(t_obj *, char *);
	t_list_parser	*tmp;

	type = -1;
	init_parser_ptr(f);
	init_obj_ptr(obj, list);
	define_groups_and_objects(obj, list);
	while (list->next)
	{
		if (list->id < 5 && type <= list->id)
			type = list->id;
		if (list->id < 6 && type == list->id)
			f[list->id](obj, list->data);
		tmp = list;
		list = list->next;
		// free(tmp->data);
		// free(tmp);
	}
	ft_printf("\n--------------------\n");
	return (check_obj(obj));
}

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	int				i;
	char			*line;
	t_list_parser	*list;

	init_obj(&parser->obj[obj_index]);
	ft_printf("Opening file: %s\tobj address %p.\n", parser->args[obj_index + 1], &parser->obj[obj_index]);
    i = 0;
    list = NULL;
	while(get_next_line(fd, &line) > 0)
	{
        if (line && ft_strlen(line) && !ft_strchr(line, '#'))
        {
            if (check_raw_data(line))
                add_list_parser(&list, line);
            else
                handle_error_parser("Error in line %s.", line);
        }
        ft_strdel(&line);
    }
	if (list == NULL || !list_parser_len(&list))
		handle_error_parser("File is empty.");
	ft_printf("Parsing file: %s\n", parser->args[obj_index + 1]);
	if (!list_parser_to_obj(&parser->obj[obj_index], list))
		handle_error_parser("Error during parsing.");
	ft_printf("NEED TO FREE T_LIST_PARSER - reader.c open_file()");
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
		if ((fd = open(parser->args[i], O_RDONLY)) == -1)
            handle_error_parser("Error when opening file.");
		open_file(fd, i - 1, parser);
	}
}