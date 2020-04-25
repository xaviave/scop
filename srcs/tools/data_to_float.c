/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:58:45 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 17:25:28 by xamartin         ###   ########lyon.fr   */
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

static void	create_indices(t_obj *obj)
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

static void	create_vertices(t_obj *obj)
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
		return ;
	if (!(obj->uv = malloc(sizeof(float) * obj->size_uv)))
		return ;
	while (++i < obj->len_vertexes)
	{
		obj->vertices[++v_id] = obj->vertexes[i].x - (obj->axis[0] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].y - (obj->axis[1] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].z - (obj->axis[2] / 2);
	}
}


static void	get_center(t_gdata *gdata, t_obj *obj)
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
		get_center(gdata, &(gdata->obj[i]));
		create_vertices(&(gdata->obj[i]));
		create_indices(&(gdata->obj[i]));
	}
	// need to catch the error from the 2 create
	return (1);
}
