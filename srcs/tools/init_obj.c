/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/26 10:52:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static void         reset_len(t_obj *obj)
{
	obj->len_mtl = 0;
    obj->len_faces = 0;
    obj->len_groups = 0;
    obj->len_lines = 0;
    obj->len_normals = 0;
    obj->len_objects = 0;
    obj->len_textures = 0;
    obj->len_vertexes = 0;
}

void	            init_obj_ptr(t_obj *obj, t_list_parser *list,
	t_parser_option *opt)
{
	
    if (!(obj->vertexes = (t_vertex *)ft_memalloc(
            sizeof(t_vertex) * opt->len[ID_V] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->textures = (t_texture *)ft_memalloc(
            sizeof(t_texture) * opt->len[ID_VT] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->normals = (t_normal *)ft_memalloc(
            sizeof(t_normal) * opt->len[ID_VN] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->faces = (t_face *)ft_memalloc(
            sizeof(t_face) * opt->len[ID_F] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->lines = (t_line *)ft_memalloc(
            sizeof(t_line) * opt->len[ID_L] + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(obj->mtl = (char **)ft_memalloc(
            sizeof(char *) * opt->len[ID_MTL] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->groups = (t_group *)ft_memalloc(
            sizeof(t_group) * opt->len[ID_G] + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->objects = (t_object *)ft_memalloc(
            sizeof(t_object) * opt->len[ID_O] + 1)))
        handle_error_parser("Error during memory allocation.");
}

void                init_obj(t_obj *obj)
{
	ft_memset(obj, 0, sizeof(t_obj));
    obj->id = -1;
}