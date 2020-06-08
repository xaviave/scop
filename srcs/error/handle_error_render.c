/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:12:49 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:35:16 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parser.h"

static void delete_t_eng(t_engine *eng, t_addr **addr)
{
    free_matrix(eng->projection);
    free_matrix(eng->view);
    free_matrix(eng->model);
    ft_memdel((void **)&(*addr)->content_addr);
}

void        delete_addr_render(t_addr **addr)
{
    int     i;

    if (*addr)
    {
        i = 0;
        printf("addr_content_type: render -> %d\n", (*addr)->content_type);
        if ((*addr)->content_type == M_OBJ_)
        {
            while (i < ((t_obj *)(*addr)->content_addr)->nb_args)
                delete_t_obj(((t_obj *)(*addr)->content_addr)[i++]);
            ft_memdel((void **)&(*addr)->content_addr);
        }
        else if ((*addr)->content_type == M_MTL_)
        {
            while (i < ((t_mtl *)(*addr)->content_addr)->nb_args)
                delete_t_mtl(((t_mtl *)(*addr)->content_addr)[i++]);
            ft_memdel((void **)&(*addr)->content_addr);
        }
        else if ((*addr)->content_type == M_BUF_)
            ft_memdel((void **)&(*addr)->content_addr);
        else if ((*addr)->content_type == M_ENG_)
            delete_t_eng(((t_engine *)(*addr)->content_addr), addr);
        if ((*addr)->next)
            delete_addr_render(&((*addr)->next));
        ft_memdel((void **)addr);
    }
}

void        handle_error_render(char *message, t_addr **addr)
{
	ft_printf("%s\n", message);
	if (addr)
	    delete_addr_render(addr);
//	while (1)
//	    ;
    exit(EXIT_FAILURE);
}
