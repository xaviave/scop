/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:49:04 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 11:51:28 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_vertex		get_vertex(t_obj *obj, int id)
{
	if (id < 0)
		id = obj->len_vertexes + id;
	return (obj->vertexes[id]);
}

t_texture		get_texture(t_obj *obj, int id)
{
	if (id < 0)
		id = obj->len_textures + id;
	return (obj->textures[id]);
}

t_normal		get_normal(t_obj *obj, int id)
{
	if (id < 0)
		id = obj->len_normals + id;
	return (obj->normals[id]);
}

t_face			get_face(t_obj *obj, int id)
{
	if (id < 0)
		id = obj->len_faces + id;
	return (obj->faces[id]);
}

t_line			get_line(t_obj *obj, int id)
{
	if (id < 0)
		id = obj->len_lines + id;
	return (obj->lines[id]);
}
