/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:11:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:28:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"
#include "../../includes/error.h"
#include "../../includes/cleaner.h"

static void     delete_t_mtl(t_mtl mtl)
{
    ft_strdel(&mtl.name); // need to set this var.
    if (mtl.ac)
        delete_texture_option(&mtl.ac->option);
    ft_memdel((void **)&mtl.ac);
    if (mtl.dc)
        delete_texture_option(&mtl.dc->option);
    ft_memdel((void **)&mtl.dc);
    if (mtl.sc)
        delete_texture_option(&mtl.sc->option);
    ft_memdel((void **)&mtl.sc);
    if (mtl.tf)
        delete_t_file(&mtl.tf->file);
    ft_memdel((void **)&mtl.tf);
    delete_t_transparent(mtl.t);
    delete_t_specular_exponent(mtl.se);
    delete_t_bump(mtl.bump);
    delete_t_disp(mtl.disp);
    delete_t_decal(mtl.decal);
    ft_memdel((void **)&mtl.shading);
}

static void     delete_t_obj(t_obj obj)
{
    int         i;

    ft_strdel(&obj.mtllib);
    delete_str_tab(obj.mtl);
    // free t_face;
    i = -1;
    while (++i < obj.len_faces)
    {
        ft_memdel((void **)&obj.faces[i].vertexes_id);
        ft_memdel((void **)&obj.faces[i].textures_id);
        ft_memdel((void **)&obj.faces[i].normals_id);
    }
    ft_memdel((void **)&obj.faces);
    // free t_groups;
    i = -1;
    while (++i < obj.len_groups)
        ft_strdel(&obj.groups[i].name);
    ft_memdel((void **)&obj.groups);
    // free t_lines;
    i = -1;
    while (++i < obj.len_lines)
    {
        ft_memdel((void **)&obj.lines[i].vertexes_id);
        ft_memdel((void **)&obj.lines[i].textures_id);
    }
    ft_memdel((void **)&obj.lines);
    // free t_normals;
    ft_memdel((void **)&obj.normals);
    // free t_objects;
    i = -1;
    while (++i < obj.len_objects)
        ft_strdel(&obj.objects[i].name);
    ft_memdel((void **)&obj.objects);
    // free t_textures;
    ft_memdel((void **)&obj.textures);
    // free t_vertexes;
    ft_memdel((void **)&obj.vertexes);
}

void                delete_addr(t_addr **addr)
{
    int             i;
    t_obj           *m_obj_;
    t_mtl           *m_mtl_;

    if (*addr)
    {
        i = 0;
        if ((*addr)->content_type == M_CHAR__)
            delete_str_tab((char **)(*addr)->content_addr);
        else if ((*addr)->content_type == M_L_PAR_)
            delete_list_parser((t_list_parser **)&(*addr)->content_addr);
        else if ((*addr)->content_type == M_OBJ_)
        {
            m_obj_ = (*addr)->content_addr;
            while (i < m_obj_[0].nb_args)
                delete_t_obj(m_obj_[i++]);
            ft_memdel((void **)&m_obj_);
        }
        else if ((*addr)->content_type == M_MTL)
        {
            m_mtl_ = (*addr)->content_addr;
            while (i < m_mtl_[0].nb_args)
                delete_t_mtl(m_mtl_[i++]);
            ft_memdel((void **)&m_mtl_);
        }
        if ((*addr)->next)
            delete_addr(&((*addr)->next));
        ft_memdel((void **)addr);
    }
}

void            handle_error_parser(char *message, t_addr **addr)
{
	ft_printf("%s\n", message);
	delete_addr(addr);
	while (1)
	    ;
    exit(EXIT_FAILURE);
}