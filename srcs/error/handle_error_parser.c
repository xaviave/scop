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

static void     delete_list_parser(t_list_parser **list)
{
    if (*list)
    {
        ft_strdel(&(*list)->data);
        if ((*list)->next)
            delete_list_parser(&((*list)->next));
        free(*list);
        *list = NULL;

    }
}

static void     delete_t_mtl(t_mtl mtl)
{
    ft_strdel(&mtl.name); // need to set this var.
    // free t_texture_colors
    if (mtl.ac)
    {
        ft_memdel((void **)&mtl.ac->option.mm);
        ft_memdel((void **)&mtl.ac->option.o);
        ft_memdel((void **)&mtl.ac->option.s);
        ft_memdel((void **)&mtl.ac->option.t);
    }
    ft_memdel((void **)&mtl.ac);
    if (mtl.dc)
    {
        ft_memdel((void **)&mtl.dc->option.mm);
        ft_memdel((void **)&mtl.dc->option.o);
        ft_memdel((void **)&mtl.dc->option.s);
        ft_memdel((void **)&mtl.dc->option.t);
    }
    ft_memdel((void **)&mtl.dc);
    if (mtl.sc)
    {
        ft_memdel((void **)&mtl.sc->option.mm);
        ft_memdel((void **)&mtl.sc->option.o);
        ft_memdel((void **)&mtl.sc->option.s);
        ft_memdel((void **)&mtl.sc->option.t);
    }
    ft_memdel((void **)&mtl.sc);
    // free t_transmission_filter
    if (mtl.tf)
    {
        ft_strdel(&mtl.tf->file.name);
        ft_strdel(&mtl.tf->file.path);
        ft_memdel((void **)&mtl.tf->file.data);
    }
    ft_memdel((void **)&mtl.tf);
    // free t_transparent
    if (mtl.t)
    {
        ft_strdel(&mtl.t->file.name);
        ft_strdel(&mtl.t->file.path);
        ft_memdel((void **)&mtl.t->option.mm);
        ft_memdel((void **)&mtl.t->option.o);
        ft_memdel((void **)&mtl.t->option.s);
        ft_memdel((void **)&mtl.t->option.t);
    }
    ft_memdel((void **)&mtl.t);
    // free t_specular_exponent
    if (mtl.se)
    {
        ft_strdel(&mtl.se->file.name);
        ft_strdel(&mtl.se->file.path);
        ft_memdel((void **)&mtl.se->option.mm);
        ft_memdel((void **)&mtl.se->option.o);
        ft_memdel((void **)&mtl.se->option.s);
        ft_memdel((void **)&mtl.se->option.t);
    }
    ft_memdel((void **)&mtl.se);
    // free t_bump
    if (mtl.bump)
    {
        ft_strdel(&mtl.bump->file.name);
        ft_strdel(&mtl.bump->file.path);
        ft_memdel((void **)&mtl.bump->option.mm);
        ft_memdel((void **)&mtl.bump->option.o);
        ft_memdel((void **)&mtl.bump->option.s);
        ft_memdel((void **)&mtl.bump->option.t);
    }
    ft_memdel((void **)&mtl.bump);
    // free t_disp
    if (mtl.disp)
    {
        ft_strdel(&mtl.disp->file.name);
        ft_strdel(&mtl.disp->file.path);
        ft_memdel((void **)&mtl.disp->option.mm);
        ft_memdel((void **)&mtl.disp->option.o);
        ft_memdel((void **)&mtl.disp->option.s);
        ft_memdel((void **)&mtl.disp->option.t);
    }
    ft_memdel((void **)&mtl.disp);
    // free t_decal
    if (mtl.decal)
    {
        ft_strdel(&mtl.decal->file.name);
        ft_strdel(&mtl.decal->file.path);
        ft_memdel((void **)&mtl.decal->option.mm);
        ft_memdel((void **)&mtl.decal->option.o);
        ft_memdel((void **)&mtl.decal->option.s);
        ft_memdel((void **)&mtl.decal->option.t);
    }
    ft_memdel((void **)&mtl.decal);
    // free t_shading
    ft_memdel((void **)&mtl.shading);
}

static void     delete_t_obj(t_obj obj)
{
    int         i;

    ft_strdel(&obj.mtllib);
    i = 0;
    while (obj.mtl[i])
        ft_strdel(&(obj.mtl[i++]));
    free(obj.mtl);
    obj.mtl = NULL;
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

static void     delete_addr(t_addr **addr)
{
    int             i;
    char            **m_char__;
    t_list_parser   *m_l_par_;
    t_obj           *m_obj_;
    t_mtl           *m_mtl_;

    if (*addr)
    {
        ft_printf("%d -> %p\n", (*addr)->content_type, (*addr)->content_addr);
        // delete addr->content* with adapted func.
        if ((*addr)->content_type == M_CHAR__)
        {
            i = 0;
            m_char__ = (*addr)->content_addr;
            while (m_char__[i])
                ft_strdel(&m_char__[i++]);
            free(m_char__);
            m_char__ = NULL;
        }
        else if ((*addr)->content_type == M_L_PAR_)
        {
            m_l_par_ = (*addr)->content_addr;
            delete_list_parser(&m_l_par_);
        }
        else if ((*addr)->content_type == M_OBJ_)
        {
            i = 0;
            m_obj_ = (*addr)->content_addr;
            while (i < m_obj_[0].nb_args)
                delete_t_obj(m_obj_[i++]);
            ft_memdel((void **)&m_obj_);
        }
        else if ((*addr)->content_type == M_MTL)
        {
            i = 0;
            m_mtl_ = (*addr)->content_addr;
            while (i < m_mtl_[0].nb_args)
                delete_t_mtl(m_mtl_[i++]);
            ft_memdel((void **)&m_mtl_);
        }
        if ((*addr)->next)
            delete_addr(&((*addr)->next));
        free(*addr);
        *addr = NULL;
    }
}

void            handle_error_parser(char *message, t_addr **addr)
{
	ft_printf("%s\n", message);
	delete_addr(addr);
    ft_printf("addr cleaned.\n");

	while (1)
	    ;

    exit(EXIT_FAILURE);
}