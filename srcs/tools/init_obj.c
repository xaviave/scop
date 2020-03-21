/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 22:41:30 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void    init_obj(t_obj *obj)
{
	obj->id = -1;
	obj->faces = NULL;
	obj->len_faces = -1;
	obj->groups = NULL;
	obj->len_groups = -1;
	obj->lines = NULL;
	obj->len_lines = -1;
	obj->normals = NULL;
	obj->len_normals = -1;
	obj->objects = NULL;
	obj->len_objects = -1;
	obj->space_vertexes = NULL;
	obj->len_space_vertexes = -1;
	obj->textures = NULL;
	obj->len_textures = -1;
	obj->vertexes = NULL;
	obj->len_vertexes = -1;
}