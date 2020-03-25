/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:10:38 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/25 23:51:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void			print_obj(t_obj *obj)
{
	int i;

	ft_printf("%d %d %d %d %d %d %d\n", obj->len_faces,  obj->len_groups,  obj->len_lines,  obj->len_normals,  obj->len_objects, obj->len_textures, obj->len_vertexes);
	i = -1;
	ft_printf("\n--------------------------------------------------\nvertexes:\n");
	if (obj->len_vertexes)
		while (++i < obj->len_vertexes)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f | w = %10f | %p\n", i, obj->vertexes[i].x, obj->vertexes[i].y, obj->vertexes[i].z, obj->vertexes[i].w, &obj->vertexes[i]);
	i = -1;
	ft_printf("\n--------------------------------------------------\ntextures:\n");
	if (obj->len_textures)
		while (++i < obj->len_textures)
			dprintf(1, "id = %4d | u = %10f | v = %10f | w = %10f\n", i, obj->textures[i].u, obj->textures[i].v, obj->textures[i].w);
	i = -1;
	ft_printf("\n--------------------------------------------------\nnormals:\n");
	if (obj->len_normals)
		while (++i < obj->len_normals)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f\n", i, obj->normals[i].x, obj->normals[i].y, obj->normals[i].z);
	i = -1;
	ft_printf("\n--------------------------------------------------\ngroups:\n");
	if (obj->len_groups)
		while (++i < obj->len_groups)
			dprintf(1, "id = %4d | name = %10s\n", i, obj->groups[i].name);
	i = -1;
	ft_printf("\n--------------------------------------------------\nobjects:\n");
	if (obj->len_objects)
		while (++i < obj->len_objects)
			dprintf(1, "id = %4d | name = %10s", i, obj->objects[i].name);
	i = -1;
	ft_printf("\n--------------------------------------------------\nlines:\n");
	if (obj->len_lines)
		while (++i < obj->len_lines)
			dprintf(1, "id = %4d\n", i);
	i = -1;
	ft_printf("\n--------------------------------------------------\nfaces %d:\n", obj->len_faces);
	if (obj->len_faces)
		while (++i < obj->len_faces)
			dprintf(1, "id = %4d | nb_vertexes = %2d\n", i, obj->faces[i].nb_vertexes);
	i = -1;
	ft_printf("\n--------------------------------------------------\nmtl:\n");
	if (obj->len_mtl)
		while (++i < obj->len_mtl)
			dprintf(1, "id = %4d | name = %s\n", i, obj->mtl[i]);
	
}
