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

static void     delete_addr(t_addr **addr)
{
    int             i;
    t_obj           *m_obj;
    char            *m_char_;
    char            **m_char__;
    t_list_parser   *m_l_par_;
    t_vertex        *m_o_ver_;
    t_texture       *m_o_tex_;
    t_normal        *m_o_nor_;
    t_face          *m_o_fac_;
    t_line          *m_o_lin_;
    t_group         *m_o_gro_;
    t_object        *m_o_obj_;

    if (*addr)
    {
        ft_printf("%d -> %p\n", (*addr)->content_type, (*addr)->content_addr);
        // delete addr->content* with adapted func.
        if ((*addr)->content_type == M_CHAR__)
        {
            i = 0;
            m_char__ = (*addr)->content_addr;
            while (m_char__[i])
                ft_strdel(&(m_char__[i++]));
            ft_memdel((void **)m_char__);
        }
        else if ((*addr)->content_type == M_CHAR_)
        {
            m_char_ = (*addr)->content_addr;
            ft_strdel(&m_char_); // ft_strdel((char **)&((*addr)->content_addr));
        }
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

	while (1)
	    ;

    exit(EXIT_FAILURE);
}