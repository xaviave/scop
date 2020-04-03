/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:11:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 13:06:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

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

static void     delete_t_obj(t_obj obj)
{
    ft_strdel(&obj.mtllib);
}

static void     delete_addr(t_addr **addr)
{
    int             i;
    char            **m_char__;
    t_list_parser   *m_l_par_;
    t_obj           *m_obj_;

    if (*addr)
    {
        ft_printf("%d -> %p\n", (*addr)->content_type, (*addr)->content_addr);
        // delete addr->content* with adapted func.
        if ((*addr)->content_type == M_CHAR__)
        {
            i = 0;
            m_char__ = (*addr)->content_addr;
            while (m_char__[i])
                ft_strdel(&(m_char__[i++])); // ft_strdel((char **)&((*addr)->content_addr));
            ft_memdel((void **)m_char__);
        }
        else if ((*addr)->content_type == M_L_PAR_)
        {
            m_l_par_ = (*addr)->content_addr;
            delete_list_parser(&m_l_par_);
        }
//        else if ((*addr)->content_type == M_OBJ_)
//        {
//            i = 0;
//            m_obj_ = (*addr)->content_addr;
//            while (m_obj_[i] != NULL)
//                delete_t_obj(m_obj_[i++]);
//            ft_memdel((void **)&m_obj_);
//        }
        if ((*addr)->next)
            delete_addr(&((*addr)->next));
//        free(*addr);
//        *addr = NULL;
    }
}

void            handle_error_parser(char *message, t_addr **addr)
{
    t_addr      *tmp;

	ft_printf("%s\n", message);
	delete_addr(addr);
    ft_printf("addr cleaned.\n");

//	while (1)
//	    ;

    exit(EXIT_FAILURE);
}