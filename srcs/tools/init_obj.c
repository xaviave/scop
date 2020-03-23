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

static void         reset_len(t_obj *obj)
{
    obj->len_faces = 0;
    obj->len_groups = 0;
    obj->len_lines = 0;
    obj->len_normals = 0;
    obj->len_objects = 0;
    obj->len_textures = 0;
    obj->len_vertexes = 0;
}

static void         malloc_obj_content(t_obj *obj)
{
    if (!(obj->faces = (t_face *)ft_memalloc(
            sizeof(t_face) * obj->len_faces + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->groups = (t_group *)ft_memalloc(
            sizeof(t_group) * obj->len_groups + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->lines = (t_line *)ft_memalloc(
            sizeof(t_line) * obj->len_lines + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->normals = (t_normal *)ft_memalloc(
            sizeof(t_normal) * obj->len_normals + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->objects = (t_object *)ft_memalloc(
            sizeof(t_object) * obj->len_objects + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->textures = (t_texture *)ft_memalloc(
            sizeof(t_texture) * obj->len_textures + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(obj->vertexes = (t_vertex *)ft_memalloc(
            sizeof(t_vertex) * obj->len_vertexes + 1)))
        handle_error_parser("Error during memory allocation.");
}

void	            init_obj_ptr(t_obj *obj, t_list_parser *list)
{
    t_list_parser   *tmp;

    tmp = list;
    while (tmp)
    {
        if (tmp->id == ID_F)
            obj->len_faces++;
        else if (tmp->id == ID_G)
            obj->len_groups++;
        else if (tmp->id == ID_L)
            obj->len_lines++;
        else if (tmp->id == ID_VN)
            obj->len_normals++;
        else if (tmp->id == ID_O)
            obj->len_objects++;
        else if (tmp->id == ID_VT)
            obj->len_textures++;
        else if (tmp->id == ID_V)
            obj->len_vertexes++;
        tmp = tmp->next;
    }
    malloc_obj_content(obj);
    reset_len(obj);
}

void                init_obj(t_obj *obj)
{
	ft_memset(obj, 0, sizeof(t_obj));
    obj->id = -1;
}