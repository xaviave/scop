/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:59:06 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:59:24 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../.././../includes/tools.h"
static void			init_obj_ptr(t_obj *obj, t_parser_option *opt,
		t_addr **addr)
{
	if (!(obj->vertexes = (t_vertex *)ft_memalloc(
			sizeof(t_vertex) * opt->len[ID_V] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->textures = (t_texture *)ft_memalloc(
			sizeof(t_texture) * opt->len[ID_VT] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->normals = (t_normal *)ft_memalloc(
			sizeof(t_normal) * opt->len[ID_VN] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->faces = (t_face *)ft_memalloc(
			sizeof(t_face) * opt->len[ID_F] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->lines = (t_line *)ft_memalloc(
			sizeof(t_line) * opt->len[ID_L] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->mtl = (char **)ft_memalloc(
			sizeof(char *) * opt->len[ID_MTL] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->groups = (t_group *)ft_memalloc(
			sizeof(t_group) * opt->len[ID_G] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->objects = (t_object *)ft_memalloc(
			sizeof(t_object) * opt->len[ID_O] + 1)))
		handle_error_parser("Error during memory allocation.", addr);
}

void				init_obj(t_obj *obj, t_parser_option *opt, int id,
		int nb_args, t_addr **addr)
{
	ft_memset(obj, 0, sizeof(t_obj));
	obj->id = id;
	obj->nb_args = nb_args;
	init_obj_ptr(obj, opt, addr);
}
