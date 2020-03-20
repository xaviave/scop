/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 16:02:17 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

void    init_obj(t_obj *obj)
{
	obj->id = -1;
	ft_bzero(obj->mtllib, 1);
	ft_bzero(obj->usemtl, 1);
	obj->faces=  NULL;
	obj->len_faces = -1;
	obj->groups=  NULL;
	obj->len_groups = -1;
	obj->lines=  NULL;
	obj->len_lines = -1;
	obj->normals=  NULL;
	obj->len_normals = -1;
	obj->objects=  NULL;
	obj->len_objects = -1;
	obj->space_vertexes=  NULL;
	obj->len_space_vertexes = -1;
	obj->textures=  NULL;
	obj->len_textures = -1;
	obj->vertexes=  NULL;
	obj->len_vertexes = -1;
}