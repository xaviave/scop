/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:58:45 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 21:02:12 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

static void	get_len_indices(t_obj *obj)
{
	int		i;

	i = -1;
	obj->size_indices = 0;
	while (++i < obj->len_faces)
	{
		obj->size_indices += 3;
		if (obj->faces[i].nb_vertexes == 4)
			obj->size_indices += 3;
	}
}

void		create_indices(t_obj *obj)
{
	int		i;
	int		j;
	int		v_id;

	get_len_indices(obj);
	if (!(obj->indices = malloc(sizeof(float) * obj->size_indices)))
		return ;
	i = -1;
	v_id = -1;
	while (++i < obj->len_faces)
	{
		j = -1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[0] - 1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[1] - 1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[2] - 1;
		if (obj->faces[i].nb_vertexes == 4)
		{
			obj->indices[++v_id] = obj->faces[i].vertexes_id[0] - 1;
			obj->indices[++v_id] = obj->faces[i].vertexes_id[2] - 1;
			obj->indices[++v_id] = obj->faces[i].vertexes_id[3] - 1;
		}
	}
}

void		create_vertices(t_obj *obj)
{
	int		i;
	int		v_id;
	
	i = -1;
	v_id = -1;
	obj->size_vertices = obj->len_vertexes * 6;
	if (!(obj->vertices = malloc(sizeof(float) * obj->size_vertices)))
		return ;
	while (++i < obj->len_vertexes)
	{
		obj->vertices[++v_id] = obj->vertexes[i].x;
		obj->vertices[++v_id] = obj->vertexes[i].y;
		obj->vertices[++v_id] = obj->vertexes[i].z;
		obj->vertices[++v_id] = (obj->len_textures ?
			obj->vertexes[i].x : obj->textures[i].u);
		obj->vertices[++v_id] = (obj->len_textures ?
			obj->vertexes[i].y : obj->textures[i].v);
		obj->vertices[++v_id] = (obj->len_textures ?
			obj->vertexes[i].z : obj->textures[i].w);
	}
}
