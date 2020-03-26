/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/26 12:41:21 by xamartin         ###   ########lyon.fr   */
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

int					*get_vertexes_id(char *str, int nb_entity)
{
	int				i;
	int				e;
	int				*tab;

	if (!(tab = (int *)malloc(sizeof(int) * nb_entity)))
		return (NULL);
	i = 0;
	e = 0;
	while (str[i] && e < nb_entity)
	{
		tab[e] = ft_atoi(str);
		e++;
		i = pass_whitespace_number(i, str);
	}
	return (tab);
}

void				parser_f(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;

	id = obj->len_faces;
	obj->faces[id].object_id = o_id;
	obj->faces[id].group_id = g_id;
	obj->faces[id].nb_vertexes = count_entity(&raw_data[1]);
	obj->faces[id].normals_id = NULL;
	obj->faces[id].textures_id = NULL;
	obj->faces[id].vertexes_id = NULL;
	obj->len_faces++;
	// ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
}

void				parser_l(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				id;

	id = obj->len_lines;
	obj->lines[id].object_id = o_id;
	obj->lines[id].group_id = g_id;
	obj->lines[id].nb_vertexes = count_entity(&raw_data[1]);
	obj->lines[id].vertexes_id = get_vertexes_id(&raw_data[1], obj->lines[id].nb_vertexes);
	obj->len_lines++;
	// ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
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
	obj->groups[id].name = ft_strdup(&raw_data[i]);
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


void				parser_pass(t_obj *obj, char *raw_data, int o_id, int g_id)
{
	int				i;

	i = pass_whitespace(6, raw_data);
	if (ft_strlen(raw_data) < 7)
	{
		(void)o_id;
		(void)g_id;
		ft_printf("Line: %s can not be parsed for now (or will be never) %p\n", raw_data, &obj);
		return ;
	}
	else if (ft_strlen(&raw_data[i]) && ft_strstr(raw_data, "mtllib"))
		obj->mtllib = ft_strdup(&raw_data[i]);
}