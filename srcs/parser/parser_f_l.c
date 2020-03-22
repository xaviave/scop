/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 21:53:37 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

<<<<<<< HEAD
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
		return NULL;
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

void				parser_f(t_obj *obj, char *raw_data)
{
	int				id;

	id = obj->len_faces;
	obj->faces[id].id = id;
	obj->faces[id].nb_vertexes = count_entity(&raw_data[1]);
	obj->faces[id].normals_id = NULL;
	obj->faces[id].textures_id = NULL;
	obj->faces[id].vertexes_id = NULL;
	obj->len_faces++;
	ft_printf("parser_f | id = %d | nb_vertexes = %d\n", id, obj->faces[id].nb_vertexes);
	// ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
}

void				parser_l(t_obj *obj, char *raw_data)
{
	int				id;

	ft_printf("parser_l\n");
	id = obj->len_lines;
	obj->lines[id].id = id;
	obj->lines[id].nb_vertexes = count_entity(&raw_data[1]);
	obj->lines[id].vertexes_id = get_vertexes_id(&raw_data[1], obj->lines[id].nb_vertexes);
	obj->len_lines++;
	// ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
}

void				parser_o(t_obj *obj, char *raw_data, int entity_id,
	int type, int nb_entity)
{
	int				i;
	int				id;

	i = 1;
	id = obj->len_objects;
	obj->objects[id].id = id;
	obj->objects[id].type = type;
	obj->objects[id].first_entity = entity_id;
	obj->objects[id].nb_entity = nb_entity;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	obj->objects[id].name = ft_strdup(&raw_data[i]);
	obj->len_objects++;
}

void				parser_g(t_obj *obj, char *raw_data, int entity_id,
	int type, int nb_entity)
{
	int				i;
	int				id;

	i = 1;
	id = obj->len_groups;
	obj->groups[id].id = id;
	obj->groups[id].type = type;
	obj->groups[id].first_entity = entity_id;
	obj->groups[id].nb_entity = nb_entity;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	obj->groups[id].name = ft_strdup(&raw_data[i]);
	obj->len_groups++;
}

void				parser_mtl_pass(t_obj *obj, char *raw_data)
{
	int				i;

	if (ft_strlen(raw_data) < 7)
	{
		ft_printf("Line: %s can not be parsed for now (or will be never - obj = %p.\n", raw_data, obj);
		return ;
	}
	i = 6;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	ft_printf("usemtl need to be a char **.");
	if (ft_strlen(&raw_data[i]) && ft_strstr(raw_data, "usemtl"))
		obj->usemtl = ft_strdup(&raw_data[i]);
	else if (ft_strlen(&raw_data[i]) && ft_strstr(raw_data, "mtllib"))
		obj->mtllib = ft_strdup(&raw_data[i]);
}