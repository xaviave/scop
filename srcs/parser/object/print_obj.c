/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:10:38 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 18:56:09 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

static void			print_int(int *nb, int nb_int, char *str)
{
	int			i;

	i = -1;
	dprintf(1, "%s:\t", str);
	while (++i < nb_int)
		dprintf(1, "%d ", nb[i]);
	dprintf(1, "\n");
}

void			print_obj(t_obj *obj)
{
	int i;

	i = -1;
	ft_printf("OBJECT: %d\n", obj->id);
	ft_printf("\n--------------------------------------------------\nvertexes:\n");
	if (obj->len_vertexes)
		while (++i < obj->len_vertexes)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f | w = %10f | object_id = %d | groups_id = %d\n", i, obj->vertexes[i].x, obj->vertexes[i].y, obj->vertexes[i].z, obj->vertexes[i].w, obj->vertexes[i].object_id, obj->vertexes[i].group_id);
	i = -1;
	ft_printf("\n--------------------------------------------------\ntextures:\n");
	if (obj->len_textures)
		while (++i < obj->len_textures)
			dprintf(1, "id = %4d | u = %10f | v = %10f | w = %10f | object_id = %d | groups_id = %d\n", i, obj->textures[i].u, obj->textures[i].v, obj->textures[i].w, obj->textures[i].object_id, obj->textures[i].group_id);
	i = -1;
	ft_printf("\n--------------------------------------------------\nnormals:\n");
	if (obj->len_normals)
		while (++i < obj->len_normals)
			dprintf(1, "id = %4d | x = %10f | y = %10f | z = %10f | object_id = %d | groups_id = %d\n", i, obj->normals[i].x, obj->normals[i].y, obj->normals[i].z, obj->normals[i].object_id, obj->normals[i].group_id);
			i = -1;
	ft_printf("\n--------------------------------------------------\nlines:\n");
	if (obj->len_lines)
		while (++i < obj->len_lines)
		{
			dprintf(1, "id = %4d | object_id = %d | groups_id = %d | has_texture %d\n", i, obj->lines[i].object_id, obj->lines[i].group_id, obj->faces[i].has_texture);
			print_int(obj->lines[i].vertexes_id, obj->lines[i].nb_vertexes, "vertexes_id");
			if (obj->lines[i].has_texture)
				print_int(obj->lines[i].textures_id, obj->lines[i].nb_vertexes, "textures_id");
		}
	i = -1;
	ft_printf("\n--------------------------------------------------\nfaces %d:\n", obj->len_faces);
	if (obj->len_faces)
		while (++i < obj->len_faces)
		{
			dprintf(1, "id = %4d | nb_vertexes = %2d | object_id = %d | groups_id = %d | has_texture %d | has_normal %d\n", i, obj->faces[i].nb_vertexes, obj->faces[i].object_id, obj->faces[i].group_id, obj->faces[i].has_texture, obj->faces[i].has_normal);
			print_int(obj->faces[i].vertexes_id, obj->faces[i].nb_vertexes, "vertexes_id");
			if (obj->faces[i].has_texture)
				print_int(obj->faces[i].textures_id, obj->faces[i].nb_vertexes, "textures_id");	
			if (obj->faces[i].has_normal)
				print_int(obj->faces[i].normals_id, obj->faces[i].nb_vertexes, "normals_id");	
		}
	i = -1;
	ft_printf("\n--------------------------------------------------\nmtl:\n");
	if (obj->len_mtl)
		while (++i < obj->len_mtl)
			dprintf(1, "id = %4d | name = %s\n", i, obj->mtl[i]);
	i = -1;
	ft_printf("\n--------------------------------------------------\ngroups:\n");
	if (obj->len_groups)
		while (++i < obj->len_groups)
			dprintf(1, "id = %4d | name = %10s | soomth = %d | object_id = %d\n", i, obj->groups[i].name, obj->groups[i].smooth, obj->groups[i].object_id);
	i = -1;
	ft_printf("\n--------------------------------------------------\nobjects:\n");
	if (obj->len_objects)
		while (++i < obj->len_objects)
			dprintf(1, "id = %4d | name = %10s | soomth = %d\n", i, obj->objects[i].name, obj->objects[i].smooth);
	ft_printf("\n");
	
}
