/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:48:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:17 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"
#include "../../includes/error.h"
#include "../../includes/cleaner.h"

void			travel_addr(t_addr *addr)
{
	if (addr->content_type == M_CHAR__)
	{
		addr->content_type = -1;
		delete_str_tab((char **)addr->content_addr);
	}
	else if (addr->content_type == M_L_PAR_)
	{
		addr->content_type = -1;
		delete_list_parser((t_list_parser **)&addr->content_addr);
	}
	if (addr->next)
		travel_addr(addr->next);
}

void			clear_parser_memory(t_addr **addr)
{
	if (addr)
		travel_addr(*addr);
}
