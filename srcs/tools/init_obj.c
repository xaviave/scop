/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/21 21:56:28 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void	init_obj_ptr(t_obj *obj, t_list_parser *list)
{
	if (get_lenght_entity(list, 4))
		if (!(obj->faces = (t_face *)malloc(sizeof(t_face) * get_lenght_entity(list, 4))))
			return ;
	if (get_lenght_entity(list, 7))
		if (!(obj->groups = (t_group *)malloc(sizeof(t_group) * get_lenght_entity(list, 7))))
			return ;
	if (get_lenght_entity(list, 5))
		if (!(obj->lines = (t_line *)malloc(sizeof(t_line) * get_lenght_entity(list, 5))))
			return ;
	if (get_lenght_entity(list, 1))
		if (!(obj->normals = (t_normal *)malloc(sizeof(t_normal) * get_lenght_entity(list, 1))))
			return ;
	if (get_lenght_entity(list, 8))
		if (!(obj->objects = (t_object *)malloc(sizeof(t_object) * get_lenght_entity(list, 8))))
			return ;
	if (get_lenght_entity(list, 2))
		if (!(obj->space_vertexes = (t_space_vertex *)malloc(sizeof(t_space_vertex) * get_lenght_entity(list, 2))))
			return ;
	if (get_lenght_entity(list, 0))
		if (!(obj->textures = (t_texture *)malloc(sizeof(t_texture) * get_lenght_entity(list, 0))))
			return ;
	if (get_lenght_entity(list, 3))
		if (!(obj->vertexes = (t_vertex *)malloc(sizeof(t_vertex) * get_lenght_entity(list, 3))))
			return ;
}

void    init_obj(t_obj *obj)
{
	obj->id = -1;
	obj->faces = NULL;
	obj->len_faces = 0;
	obj->groups = NULL;
	obj->len_groups = 0;
	obj->lines = NULL;
	obj->len_lines = 0;
	obj->normals = NULL;
	obj->len_normals = 0;
	obj->objects = NULL;
	obj->len_objects = 0;
	obj->space_vertexes = NULL;
	obj->len_space_vertexes = 0;
	obj->textures = NULL;
	obj->len_textures = 0;
	obj->vertexes = NULL;
	obj->len_vertexes = 0;
}