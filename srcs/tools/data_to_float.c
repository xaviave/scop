/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:49:24 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:49:48 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

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

void		rand_color(int face_id, t_obj *obj, int v0, int v1, int v2)
{
	float	f;

	f = face_id / (double)obj->len_faces;
	if (f < 0.3)
		f = 1 - f;
	if (face_id % 7 == 0)
	{
		obj->vertices[v0 * 6 + 3] = f;
		obj->vertices[v1 * 6 + 4] = f;
	}
	if (face_id % 5 == 0)
	{
		obj->vertices[v2 * 6 + 5] = f;
		obj->vertices[v1 * 6 + 4] = f;
	}
	if (face_id % 4 == 0)
		obj->vertices[v0 * 6 + 3] = f;
	if (face_id % 3 == 0)
		obj->vertices[v1 * 6 + 4] = f;
	else if (face_id % 2 == 0)
		obj->vertices[v2 * 6 + 5] = f;
}

static int	create_indices(t_obj *obj)
{
	int		i;
	int		j;
	int		v_id;

	get_len_indices(obj);
	if (!(obj->indices = malloc(sizeof(float) * obj->size_indices)))
		return (0);
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
	return (1);
}

static int	create_vertices(t_obj *obj)
{
	int		i;
	int		v_id;
	int		uv_id;

	i = -1;
	v_id = -1;
	uv_id = -1;
	obj->size_vertices = obj->len_vertexes * 3;
	obj->size_uv = obj->len_vertexes * 2;
	if (!(obj->vertices = malloc(sizeof(float) * obj->size_vertices)))
		return (0);
	if (!(obj->uv = malloc(sizeof(float) * obj->size_uv)))
		return (0);
	while (++i < obj->len_vertexes)
	{
		obj->vertices[++v_id] = obj->vertexes[i].x - (obj->axis[0] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].y - (obj->axis[1] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].z - (obj->axis[2] / 2);
	}
	return (1);
}

static void	get_center(t_obj *obj)
{
	int		i;

	i = -1;
	while (++i < obj->len_vertexes)
	{
		if (!i || (obj->min[0] > obj->vertexes[i].x))
			obj->min[0] = obj->vertexes[i].x;
		if (!i || (obj->max[0] < obj->vertexes[i].x))
			obj->max[0] = obj->vertexes[i].x;
		if (!i || (obj->min[1] > obj->vertexes[i].y))
			obj->min[1] = obj->vertexes[i].y;
		if (!i || (obj->max[1] < obj->vertexes[i].y))
			obj->max[1] = obj->vertexes[i].y;
		if (!i || (obj->min[2] > obj->vertexes[i].z))
			obj->min[2] = obj->vertexes[i].z;
		if (!i || (obj->max[2] < obj->vertexes[i].z))
			obj->max[2] = obj->vertexes[i].z;
	}
	ft_bzero(obj->axis, sizeof(float[3]));
	vertex3_add(obj->axis, obj->max, obj->min);
}

int			init_all_obj(t_gdata *gdata)
{
	int		i;

	i = -1;
	while (++i < gdata->nb_objs)
	{
		get_center(&(gdata->obj[i]));
		if (!(create_vertices(&(gdata->obj[i]))))
			return (0);
		if (!(create_indices(&(gdata->obj[i]))))
			return (0);
	}
	return (1);
}
