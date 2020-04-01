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

void            handle_error_parser(char *message, t_addr **addr)
{
    t_addr      *tmp;

	ft_printf("%s\n", message);
	if (*addr)
    {
	    tmp = *addr;
	    while (tmp)
        {
            ft_printf("%s\n", tmp->content_type);
            // envoyer le contenu a sa fonction de deletion a l'aide de tmp->content_type.
	        tmp = tmp->next;
        }
    }
//	addr = NULL;
//	while (1)
//	    ;
    exit(EXIT_FAILURE);
}