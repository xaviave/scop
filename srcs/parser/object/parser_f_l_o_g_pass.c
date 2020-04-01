/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l_o_g_pass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 01:08:40 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/scop.h"

int					count_entity(char *str)
{
	int				i;
	int				entity;

	i = 0;
	entity = 0;
	while (str[i])
	{
		i = pass_whitespace(i, str);
		if (str[i])
			entity++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (entity);
}

int					pass_id(int i, char *str, short delim_id)
{
	short			delim;

	delim = 0;
	i = pass_whitespace(i, str);
	while (str[i] && delim < delim_id)
		if (str[i] == '/')
			delim++;
		i++;
	return (i - 1);
}

int					*get_vertexes_id(char *str, int nb_entity, short pos_id)
{
	int				i;
	int				e;
	int				*tab;

	if (!(tab = (int *)malloc(sizeof(int) * nb_entity)))
		return (NULL);
	i = 0;
	e = -1;
	while (str[i] && ++e < nb_entity)
	{
		i = pass_id(i, str, pos_id);
		tab[e] = ft_atoi(&str[i]);
    	while (str[i] && str[i] != '\t' && str[i] != ' ')
        	i++;
	}
	return (tab);
}

void				parser_f(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;
	int				nb_delim;

	id = obj->len_faces;
	obj->faces[id].object_id = o_id;
	obj->faces[id].group_id = g_id;
	obj->faces[id].nb_vertexes = count_entity(&raw_data[1]);
	nb_delim = count_char(&raw_data[1], '/');
	obj->faces[id].vertexes_id = get_vertexes_id(&raw_data[1], obj->faces[id].nb_vertexes, 0);
	if (nb_delim == 3 || nb_delim == 4)
	{
		obj->faces[id].has_texture++;
		obj->faces[id].textures_id = get_vertexes_id(&raw_data[1], obj->faces[id].nb_vertexes, 1);
	}
	if (nb_delim > 5)
	{
		obj->faces[id].has_normal++;
		obj->faces[id].normals_id = get_vertexes_id(&raw_data[1], obj->faces[id].nb_vertexes, 2);
	}
	obj->len_faces++;
}

void				parser_l(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;

	id = obj->len_lines;
	obj->lines[id].object_id = o_id;
	obj->lines[id].group_id = g_id;
	obj->lines[id].nb_vertexes = count_entity(&raw_data[1]);
	obj->lines[id].vertexes_id = get_vertexes_id(&raw_data[1], obj->lines[id].nb_vertexes, 0);
	if (ft_strchr(raw_data, '/'))
	{
		obj->faces[id].has_texture++;
		obj->lines[id].textures_id = get_vertexes_id(&raw_data[1], obj->lines[id].nb_vertexes, 1);
	}
	obj->len_lines++;
}

void				parser_o(t_obj *obj, char *raw_data)
{
	int				i;
	int				id;

	id = obj->len_objects;
	i = pass_whitespace(1, raw_data);
	obj->objects[id].name = ft_strdup(&raw_data[i]);
	obj->len_objects++;
}

void				parser_g(t_obj *obj, char *raw_data, int o_id)
{
	int				i;
	int				id;

	id = obj->len_groups;
	obj->groups[id].object_id = o_id;
	// if no name after g - default = default
	// need to change to char **name | could have many names
	// If there are multiple groups on one line, the data that follows belong to all groups
	i = pass_whitespace(1, raw_data);
	if (i > 1)
		obj->groups[id].name = ft_strdup(&raw_data[i]);
	else
	{
		obj->groups[id].name = (obj->nb_default > 0) ?
			ft_strjoin("default_", ft_itoa(obj->nb_default)) : ft_strdup("default") ;
		obj->nb_default++;
	}
	
	obj->len_groups++;
}

void				parser_mtl(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;

	(void)o_id;
	(void)g_id;
	i = pass_whitespace(6, raw_data);
	obj->mtl[obj->len_mtl] = ft_strdup(&raw_data[i]);
	obj->len_mtl++;
}

/*
** "s off" mean no smoothing, ft_atoi return 0 as adefault value else the smoothing value
** if smooth > 0, it means on
*/

void				parser_pass_obj(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;
	short			smooth;

	if (raw_data[0] == 's')
	{
		i = pass_whitespace(1, raw_data);
		smooth = ft_atoi(&raw_data[i]);
		obj->objects[o_id].smooth = smooth;
		obj->groups[g_id].smooth = smooth;
	}
	else if (ft_strlen(raw_data) < 7)
		return ;
	else if (ft_strlen(&raw_data[6]) && ft_strstr(raw_data, "mtllib"))
	{
		i = pass_whitespace(6, raw_data);
		obj->mtllib = ft_strdup(&raw_data[i]);
	}
}