/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l_o_g_pass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:27:19 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../../../includes/parser.h"

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
		return (0);
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

int 				parser_f(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;
	int				nb_delim;

	id = obj->len_faces;
	obj->faces[id].object_id = o_id;
	obj->faces[id].group_id = g_id;
	obj->faces[id].nb_vertexes = count_entity(&raw_data[1]);
	nb_delim = count_char(&raw_data[1], '/');
	if (!(obj->faces[id].vertexes_id = get_vertexes_id(&raw_data[1],
	        obj->faces[id].nb_vertexes, 0)))
	    return (0);
	if ((nb_delim == 3 || nb_delim == 4) && obj->faces[id].has_texture++)
	{
		if (!(obj->faces[id].textures_id = get_vertexes_id(&raw_data[1],
		        obj->faces[id].nb_vertexes, 1)))
		    return (0);
	}
	if (nb_delim > 5 && (obj->faces[id].has_normal++))
	{
		if (!(obj->faces[id].normals_id = get_vertexes_id(&raw_data[1],
		        obj->faces[id].nb_vertexes, 2)))
		    return (0);
	}
	obj->len_faces++;
	return (1);
}

int 				parser_l(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;

	id = obj->len_lines;
	obj->lines[id].object_id = o_id;
	obj->lines[id].group_id = g_id;
	obj->lines[id].nb_vertexes = count_entity(&raw_data[1]);
	if (!(obj->lines[id].vertexes_id = get_vertexes_id(&raw_data[1],
	        obj->lines[id].nb_vertexes, 0)))
	    return (0);
	if (ft_strchr(raw_data, '/'))
	{
		obj->faces[id].has_texture++;
		if (!(obj->lines[id].textures_id = get_vertexes_id(&raw_data[1],
		        obj->lines[id].nb_vertexes, 1)))
		    return (0);
	}
	obj->len_lines++;
    return (1);
}

int 				parser_o(t_obj *obj, char *raw_data)
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

int 				parser_g(t_obj *obj, char *raw_data, int o_id)
{
	int				i;
	int				id;
	char            *tmp;

	id = obj->len_groups;
	obj->groups[id].object_id = o_id;
	// need to change to char **name | could have many names
	// If there are multiple groups on one line, the data that follows belong to all groups
	i = pass_whitespace(1, raw_data);
	if (i > 1)
	{
        if (!(obj->groups[id].name = ft_strdup(&raw_data[i])))
            return (0);
    }
	else
	{
	    if (!(tmp = ft_itoa(obj->nb_default)))
	        return (0);
		if (!(obj->groups[id].name = (obj->nb_default > 0) ? ft_strjoin("default_", tmp) : ft_strdup("default")))
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

int 				parser_mtl(t_obj *obj, char *raw_data, int o_id, int g_id)
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
** "s off" mean no smoothing, ft_atoi return 0 as default value else the smoothing value
** if smooth > 0, it means on
*/

int 				parser_pass_obj(t_obj *obj, char *raw_data, int o_id, int g_id)
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
        return (1);
    else if (ft_strlen(&raw_data[6]) && ft_strstr(raw_data, "mtllib"))
    {
        i = pass_whitespace(6, raw_data);
        if (!(obj->mtllib = ft_strdup(&raw_data[i])))
            return (0);
    }
    return (1);
}