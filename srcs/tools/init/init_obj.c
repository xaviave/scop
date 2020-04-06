/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/04/05 12:30:43 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/tools.h"

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
	if (!(obj->mtl = (char **)malloc(sizeof(char *) * opt->len[ID_MTL] + 1)))
        handle_error_parser("Error during memory allocation.", addr);
	obj->mtl[opt->len[ID_MTL]] = NULL;
    if (!(obj->groups = (t_group *)ft_memalloc(
            sizeof(t_group) * opt->len[ID_G] + 1)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->objects = (t_object *)ft_memalloc(
            sizeof(t_object) * opt->len[ID_O] + 1)))
        handle_error_parser("Error during memory allocation.", addr);
}

void                init_obj(t_obj *obj, t_parser_option *opt, int id,
        int nb_args, t_addr **addr)
{
	ft_memset(obj, 0, sizeof(t_obj));
    obj->id = id;
    obj->nb_args = nb_args;
	init_obj_ptr(obj, opt, addr);
}