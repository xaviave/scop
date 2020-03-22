/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:27:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 12:23:05 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

int							len_list_parser_id(t_list_parser *list, int id)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = list;
	while (tmp->next && tmp->next->id == id)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int							get_lenght_entity(t_list_parser *list, int id)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = list;
	while (tmp->next)
	{
		if (tmp->id == id)
			i++;
		tmp = tmp->next;
	}
	return (i);
}