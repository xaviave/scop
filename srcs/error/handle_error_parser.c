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
    if (*addr)
    {
        ft_printf("%d - %p\n", (*addr)->content_type, *addr);
        // delete addr->content* with adapted func.
        if ((*addr)->next)
            delete_addr(&((*addr)->next));
        free(*addr);
        *addr = NULL;
    }
}

void            handle_error_parser(char *message, t_addr **addr)
{
    t_addr      *tmp;

	ft_printf("%s\n", message);
	delete_addr(addr);
    ft_printf("addr cleaned.\n");

//    *addr = NULL;
//    addr = NULL;
//	while (1)
//	    ;

    exit(EXIT_FAILURE);
}