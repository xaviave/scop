/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:48:24 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:49:14 by ltoussai         ###   ########lyon.fr   */
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
