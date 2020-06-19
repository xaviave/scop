/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:14:01 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:27:29 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int					parser_vt(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;
	int				id;

	i = 2;
	id = obj->len_textures;
	obj->textures[id].object_id = o_id;
	obj->textures[id].group_id = g_id;
	obj->textures[id].u = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->textures[id].v = optional_value_double(&raw_data[i], 0.0);
	i = pass_whitespace_str(i, raw_data);
	obj->textures[id].w = optional_value_double(&raw_data[i], 0.0);
	obj->len_textures++;
	return (1);
}

int					parser_vn(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;
	int				id;

	i = 2;
	id = obj->len_normals;
	obj->normals[id].object_id = o_id;
	obj->normals[id].group_id = g_id;
	obj->normals[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->normals[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->normals[id].z = ft_atof(&raw_data[i]);
	obj->len_normals++;
	return (1);
}

int					parser_v(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;
	int				id;

	i = 1;
	id = obj->len_vertexes;
	obj->vertexes[id].object_id = o_id;
	obj->vertexes[id].group_id = g_id;
	obj->vertexes[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->vertexes[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->vertexes[id].z = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	obj->vertexes[id].w = optional_value_double(&raw_data[i], 1.0);
	obj->len_vertexes++;
	return (1);
}
