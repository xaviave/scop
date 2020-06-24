/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:55:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:20 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"
#include "../../includes/parser_struct.h"

void		*addr_add(void *content, int type, t_addr **addr)
{
	t_addr	*new;

	if (!(content) || !(new = (t_addr*)malloc(sizeof(t_addr))))
		return (NULL);
	new->content_addr = content;
	new->content_type = type;
	new->next = *addr;
	*addr = new;
	return (content);
}
