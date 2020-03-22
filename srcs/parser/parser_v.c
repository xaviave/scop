/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:24:18 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/22 15:35:48 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void				parser_vt(t_obj *obj, char *raw_data)
{
	int				i;
	int				id;

	i = 2;
	id = obj->len_textures;
	obj->textures[id].id = id;
	obj->textures[id].u = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->textures[id].v = optionnal_value_double(&raw_data[i], 0.0);
	i = pass_whitespace_double(i, raw_data);
	obj->textures[id].w = optionnal_value_double(&raw_data[i], 0.0);
	obj->len_textures++;
}

void				parser_vn(t_obj *obj, char *raw_data)
{
	int				i;
	int				id;

	i = 2;
	id = obj->len_normals;
	obj->normals[id].id = id;
	obj->normals[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->normals[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->normals[id].z = ft_atof(&raw_data[i]);
	obj->len_normals++;
}

void				parser_v(t_obj *obj, char *raw_data)
{
	int				i;
	int				id;

	i = 1;
	id = obj->len_vertexes;
	obj->vertexes[id].id = id;
	obj->vertexes[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->vertexes[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->vertexes[id].z = ft_atof(&raw_data[i]);
	i = pass_whitespace_double(i, raw_data);
	obj->vertexes[id].w = optionnal_value_double(&raw_data[i], 1.0);
	obj->len_vertexes++;
}
