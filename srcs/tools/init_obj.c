/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:37:51 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/26 11:45:52 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static void			init_obj_ptr(t_obj *obj, t_parser_option *opt,
        t_addr **addr)
{
    if (!(obj->vertexes = addr_add((t_vertex *)ft_memalloc(
            sizeof(t_vertex) * opt->len[ID_V] + 1), M_O_VER_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->textures = addr_add((t_texture *)ft_memalloc(
            sizeof(t_texture) * opt->len[ID_VT] + 1), M_O_TEX_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->normals = addr_add((t_normal *)ft_memalloc(
            sizeof(t_normal) * opt->len[ID_VN] + 1), M_O_NOR_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->faces = addr_add((t_face *)ft_memalloc(
            sizeof(t_face) * opt->len[ID_F] + 1), M_O_FAC_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->lines = addr_add((t_line *)ft_memalloc(
            sizeof(t_line) * opt->len[ID_L] + 1), M_O_LIN_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
	if (!(obj->mtl = addr_add((char **)ft_memalloc(
            sizeof(char *) * opt->len[ID_MTL] + 1), M_CHAR__, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->groups = addr_add((t_group *)ft_memalloc(
            sizeof(t_group) * opt->len[ID_G] + 1), M_O_GRO_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
    if (!(obj->objects = addr_add((t_object *)ft_memalloc(
            sizeof(t_object) * opt->len[ID_O] + 1), M_O_OBJ_, addr)))
        handle_error_parser("Error during memory allocation.", addr);
}

void                init_obj(t_obj *obj, t_parser_option *opt, t_addr **addr)
{
	ft_memset(obj, 0, sizeof(t_obj));
    obj->id = -1;
	init_obj_ptr(obj, opt, addr);
}