/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:58:45 by xamartin          #+#    #+#             */
/*   Updated: 2020/05/21 17:36:18 by xamartin         ###   ########lyon.fr   */
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

void		rand_color(int face_id, int len_face, float c[3])
{
	float	f;

	f = face_id / (double)len_face;
	if (face_id % 3 == 0)
	{
		fprintf(stderr, "3 - %d %f\n", face_id, f);
		c[0] = (exp(f) - exp(-pow(f, 2)));
		c[1] = (exp(f) + exp(1) * log(f));
		c[2] = f;
	}
	else if (face_id % 2 == 0)
	{
		fprintf(stderr, "2 - %d %f\n", face_id, f);
		c[0] = cos(f) - exp(f);
		c[1] = f;
		c[2] = f + exp(-pow(f, 3));
	}
	else
	{
		fprintf(stderr, "1 - %d %f\n", face_id, f);
		c[0] = f;
		c[1] = f;
		c[2] = f;
	}
}

static void	create_vertices(t_obj *obj)
{
	int		i;
	int		v_id;
	float	c[3];
	
	i = -1;
	v_id = -1;
	obj->size_vertices = obj->len_vertexes * 6;
	if (!(obj->vertices = malloc(sizeof(float) * obj->size_vertices)))
		return ;
	while (++i < obj->len_vertexes)
	{
		rand_color(i / 3, obj->len_faces / 3, c);
		fprintf(stderr, "%f %f %f\n", c[0], c[1], c[2]);
		obj->vertices[++v_id] = obj->vertexes[i].x - (obj->axis[0] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].y - (obj->axis[1] / 2);
		obj->vertices[++v_id] = obj->vertexes[i].z - (obj->axis[2] / 2);
		obj->vertices[++v_id] = c[0];
		obj->vertices[++v_id] = c[1];
		obj->vertices[++v_id] = c[2];
	}
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
		create_vertices(&(gdata->obj[i]));
		create_indices(&(gdata->obj[i]));
	}
	// need to catch the error from the 2 create
	return (1);
}
