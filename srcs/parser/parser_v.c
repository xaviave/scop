/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:24:18 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 20:31:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void				parser_vt(t_obj *obj, char *raw_data, int id)
{
	int				i;

	i = 0;
	obj->textures[id].u = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->textures[id].v = optionnal_value_float(&raw_data[i], 0.0);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->textures[id].w = optionnal_value_float(&raw_data[i], 0.0);
}

void				parser_vn(t_obj *obj, char *raw_data, int id)
{
	int				i;

	i = 0;
	obj->normals[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->normals[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->normals[id].z = ft_atof(&raw_data[i]);
}

void				parser_vp(t_obj *obj, char *raw_data, int id)
{
	int				i;

	i = 0;
	obj->space_vertexes[id].u = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->space_vertexes[id].v = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->space_vertexes[id].w = optionnal_value_float(&raw_data[i], 1.0);
}

void				parser_v(t_obj *obj, char *raw_data, int id)
{
	int				i;

	i = 0;
	obj->vertexes[id].x = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->vertexes[id].y = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->vertexes[id].z = ft_atof(&raw_data[i]);
	i = pass_whitespace_float(i - 1, raw_data);
	obj->vertexes[id].w = optionnal_value_float(&raw_data[i], 1.0);
}
