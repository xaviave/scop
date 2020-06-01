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

void        delete_addr_render(t_addr **addr)
{
    int     i;

    if (*addr)
    {
        i = 0;
        printf("addr_content_type -> %d\n", (*addr)->content_type);
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
    exit(EXIT_FAILURE);
}
