/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l_o_g_pass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:08 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:13 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int					parser_o(t_obj *obj, char *raw_data)
{
	int				i;
	int				id;

	id = obj->len_objects;
	i = pass_whitespace(1, raw_data);
	if (!(obj->objects[id].name = ft_strdup(&raw_data[i])))
		return (0);
	obj->len_objects++;
	return (1);
}

static int			parser_g_greater(t_obj *obj, char *raw_data, int i, int id)
{
	if (!(obj->groups[id].name = ft_strdup(&raw_data[i])))
		return (0);
	obj->len_groups++;
	return (1);
}

int					parser_g(t_obj *obj, char *raw_data, int o_id)
{
	int				i;
	int				id;
	char			*tmp;

	id = obj->len_groups;
	obj->groups[id].object_id = o_id;
	i = pass_whitespace(1, raw_data);
	if (i > 1)
		return (parser_g_greater(obj, raw_data, i, id));
	else
	{
		if (!(tmp = ft_itoa(obj->nb_default)))
			return (0);
		if (!(obj->groups[id].name = (obj->nb_default > 0) ?
			ft_strjoin("default_", tmp) : ft_strdup("default")))
		{
			ft_strdel(&tmp);
			return (0);
		}
		ft_strdel(&tmp);
		obj->nb_default++;
	}
	obj->len_groups++;
	return (1);
}

int					parser_mtl(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;

	(void)o_id;
	(void)g_id;
	i = pass_whitespace(6, raw_data);
	if (!(obj->mtl[obj->len_mtl] = ft_strdup(&raw_data[i])))
		return (0);
	obj->len_mtl++;
	return (1);
}

/*
** "s off" mean no smoothing, ft_atoi return 0 as default value
**else the smoothing value
** if smooth > 0, it means on
*/

int					parser_pass_obj(t_obj *obj, char *raw_data, int o_id,
	int g_id)
{
	int				i;
	short			smooth;

	if (raw_data[0] == 's')
	{
		i = pass_whitespace(1, raw_data);
		smooth = ft_atoi(&raw_data[i]);
		if (o_id >= 0)
			obj->objects[o_id].smooth = smooth;
		if (g_id >= 0)
			obj->groups[g_id].smooth = smooth;
	}
	else if (ft_strlen(raw_data) < 7)
		return (1);
	else if (ft_strlen(&raw_data[6]) && ft_strstr(raw_data, "mtllib"))
	{
		i = pass_whitespace(6, raw_data);
		if (!(obj->mtllib = ft_strdup(&raw_data[i])))
			return (0);
	}
	return (1);
}
