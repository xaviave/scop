/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/24 21:15:16 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static void			print_obj(t_obj *obj)
{
	int i;

	ft_printf("%d %d %d %d %d %d %d\n", obj->len_faces,  obj->len_groups,  obj->len_lines,  obj->len_normals,  obj->len_objects, obj->len_textures, obj->len_vertexes);
	i = -1;
	ft_printf("\n--------------------------------------------------\nvertexes:\n");
	if (obj->len_vertexes)
		while (++i < obj->len_vertexes)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f | w = %10f | %p\n", obj->vertexes[i].id, obj->vertexes[i].x, obj->vertexes[i].y, obj->vertexes[i].z, obj->vertexes[i].w, &obj->vertexes[i]);
	i = -1;
	ft_printf("\n--------------------------------------------------\ntextures:\n");
	if (obj->len_textures)
		while (++i < obj->len_textures)
			dprintf(1, "id = %4d | u = %10f | v = %10f | w = %10f\n", obj->textures[i].id, obj->textures[i].u, obj->textures[i].v, obj->textures[i].w);
	i = -1;
	ft_printf("\n--------------------------------------------------\nnormals:\n");
	if (obj->len_normals)
		while (++i < obj->len_normals)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f\n", obj->normals[i].id, obj->normals[i].x, obj->normals[i].y, obj->normals[i].z);
	i = -1;
	ft_printf("\n--------------------------------------------------\ngroups:\n");
	if (obj->len_groups)
		while (++i < obj->len_groups)
			dprintf(1, "id = %4d | name = %10s\n", obj->groups[i].id, obj->groups[i].name);
	i = -1;
	ft_printf("\n--------------------------------------------------\nobjects:\n");
	if (obj->len_objects)
		while (++i < obj->len_objects)
			dprintf(1, "id = %4d | name = %10s", obj->objects[i].id, obj->objects[i].name);
	i = -1;
	ft_printf("\n--------------------------------------------------\nlines:\n");
	if (obj->len_lines)
		while (++i < obj->len_lines)
			dprintf(1, "id = %4d\n", obj->lines[i].id);
	i = -1;
	ft_printf("\n--------------------------------------------------\nfaces %d:\n", obj->len_faces);
	if (obj->len_faces)
		while (++i < obj->len_faces)
			dprintf(1, "id = %4d | nb_vertexes = %2d\n", obj->faces[i].id, obj->faces[i].nb_vertexes);

}

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 0;
	// print_obj(obj);
	// need to check if there's vertexes and faces or other things
	// need to check all the v - vn - vt ids in lines and faces
	return (err);
}

static void			define_groups_and_objects(t_obj *obj, t_list_parser *list)
{
    int             len_list;
	t_list_parser	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->id == ID_G || tmp->id == ID_O)
        {
		    len_list = len_list_parser_id(tmp);
			// need to add a value smoothing group
			tmp->id == ID_G ? \
			parser_g(obj, tmp->data, len_list) : \
			parser_o(obj, tmp->data, len_list);
        }
		tmp = tmp->next;
	}
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	void			(*f[6])(t_obj *, char *);
	t_list_parser	*tmp;

	init_parser_ptr(f);
	init_obj_ptr(obj, list);
	define_groups_and_objects(obj, list);
	tmp = list;
	while (tmp)
	{
		if (tmp->id < 6)
			f[tmp->id](obj, tmp->data);
		tmp = tmp->next;
	}
	return (check_obj(obj));
}

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	char			*line;
	t_list_parser	*list;

	init_obj(&parser->obj[obj_index]);
	ft_printf("Opening file: %s\n\n", parser->args[obj_index + 1]);
    list = NULL;
	while(get_next_line(fd, &line) > 0)
	{
        if (line && ft_strlen(line) > 1)
        {
            if (check_raw_data(line))
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
	ft_printf("Parsing file: %s\n", parser->args[obj_index + 1]);
	if (!list_parser_to_obj(&parser->obj[obj_index], list))
		handle_error_parser("Error during parsing.");
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