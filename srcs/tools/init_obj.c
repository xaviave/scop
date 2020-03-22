/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/22 15:38:26 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void	init_obj_ptr(t_obj *obj, t_list_parser *list)
{
    // Important de discuter de cette fonction.
	if (get_lenght_entity(list, 3))
		if (!(obj->faces = (t_face *)malloc(sizeof(t_face) * get_lenght_entity(list, 4))))
			return ;
	else if (get_lenght_entity(list, 6))
		if (!(obj->groups = (t_group *)malloc(sizeof(t_group) * get_lenght_entity(list, 7))))
			return ;
	else if (get_lenght_entity(list, 4))
		if (!(obj->lines = (t_line *)malloc(sizeof(t_line) * get_lenght_entity(list, 5))))
			return ;
	else if (get_lenght_entity(list, 1))
		if (!(obj->normals = (t_normal *)malloc(sizeof(t_normal) * get_lenght_entity(list, 1))))
			return ;
	else if (get_lenght_entity(list, 7))
		if (!(obj->objects = (t_object *)malloc(sizeof(t_object) * get_lenght_entity(list, 8))))
			return ;
	else if (get_lenght_entity(list, 0))
		if (!(obj->textures = (t_texture *)malloc(sizeof(t_texture) * get_lenght_entity(list, 0))))
			return ;
	else if (get_lenght_entity(list, 2))
		if (!(obj->vertexes = (t_vertex *)malloc(sizeof(t_vertex) * get_lenght_entity(list, 3))))
			return ;
}

void    init_obj(t_obj *obj)
{
	ft_memset(obj, 0, sizeof(t_obj));
    obj->id = -1;
}