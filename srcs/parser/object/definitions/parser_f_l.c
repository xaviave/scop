/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:08 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:17:30 by ltoussai         ###   ########lyon.fr   */
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
	while (str[i] && delim < delim_id)
	{
		if (str[i] == '/')
			delim++;
		i++;
	}
	return (ft_isdigit(str[i]) ? i : -1);
}

int					*get_vertexes_id(char *str, int nb_entity, short pos_id)
{
	int				i;
	int				e;
	int				*tab;

	if (!(tab = (int *)malloc(sizeof(int) * nb_entity)))
		return (0);
	i = 0;
	e = 0;
	while (str[i] && e < nb_entity)
	{
		i = pass_whitespace(i, str);
		if ((i = pass_id(i, str, pos_id)) == -1)
		{
			free(tab);
			tab = NULL;
			break ;
		}
		tab[e++] = ft_atoi(&str[i]);
		while (str[i] && str[i] != '\t' && str[i] != ' ')
			i++;
	}
	return (tab);
}

int					parser_f(t_obj *obj, char *raw_data, int o_id, int g_id)
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

int					parser_l(t_obj *obj, char *raw_data, int o_id, int g_id)
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
