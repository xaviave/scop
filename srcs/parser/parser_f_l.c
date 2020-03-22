/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 14:37:54 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void				parser_f(t_obj *obj, char *raw_data)
{
	ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
    ft_printf("parser_f | line: %s | obj = %p\nNo parsing\n", raw_data, obj);
}

void				parser_l(t_obj *obj, char *raw_data)
{
	ft_printf("NEED TO HANDLE NEGATIV ID | -1 IS THE LAST ID\n");
    ft_printf("parser_l | line: %s | obj = %p\nNo parsing\n", raw_data, obj);
}

void				parser_o(t_obj *obj, char *raw_data, int entity_id,
	int type, int nb_entity)
{
	int				i;

	i = 1;
	obj->objects[obj->len_objects].type = type;
	obj->objects[obj->len_objects].first_entity = entity_id;
	obj->objects[obj->len_objects].nb_entity = nb_entity;
	obj->objects[obj->len_objects].id = obj->len_objects;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	obj->objects[obj->len_objects].name = ft_strdup(&raw_data[i]);
	obj->len_objects++;
}

void				parser_g(t_obj *obj, char *raw_data, int entity_id,
	int type, int nb_entity)
{
	int				i;

	i = 1;
	obj->groups[obj->len_groups].type = type;
	obj->groups[obj->len_groups].first_entity = entity_id;
	obj->groups[obj->len_groups].nb_entity = nb_entity;
	obj->groups[obj->len_groups].id = obj->len_groups;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	obj->groups[obj->len_groups].name = ft_strdup(&raw_data[i]);
	obj->len_groups++;
}

void				parser_mtl_pass(t_obj *obj, char *raw_data)
{
	int				i;

	if (ft_strlen(raw_data) < 7)
	{
		ft_printf("Line: %s can not be parsed - obj = %p\n", raw_data, obj);
		return ;
	}
	i = 6;
	while (raw_data[i] && raw_data[i] == '\t' && raw_data[i] == ' ')
		i++;
	if (ft_strlen(&raw_data[i]) && ft_strstr(raw_data, "usemtl"))
		obj->usemtl = ft_strdup(&raw_data[i]);
	else if (ft_strlen(&raw_data[i]) && ft_strstr(raw_data, "mtllib"))
		obj->mtllib = ft_strdup(&raw_data[i]);
}