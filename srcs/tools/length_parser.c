/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:53:37 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:54:13 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

static int				calc_id_g(t_list_parser *tmp)
{
	int					i;
	int					id;

	i = 0;
	id = tmp->id;
	while (tmp)
	{
		if (tmp->id == id)
			i++;
		else if (tmp->id != ID_ERR_OBJ)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

static int				calc_id_o(t_list_parser *tmp)
{
	int					i;
	int					id;

	i = 0;
	id = tmp->id;
	if (id == ID_G)
		return (1);
	while (tmp)
	{
		if (tmp->id == ID_O)
			break ;
		else if (tmp->id != ID_ERR_OBJ)
		{
			i++;
			if (tmp->id == ID_G)
				break ;
		}
		tmp = tmp->next;
	}
	if ((tmp == NULL && i == 0) || (tmp && tmp->id == ID_O && i == 0))
		handle_error_parser("Syntax error.", NULL);
	return (i);
}

int						len_list_parser_id(t_list_parser *list)
{
	t_list_parser		*tmp;

	if (list->next == NULL)
	{
		printf("%s\n", list->data);
		handle_error_parser("Error in line", NULL);
	}
	tmp = list->next;
	while (tmp && tmp->id == ID_ERR_OBJ)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		printf("%s\n", list->data);
		handle_error_parser("Error in line", NULL);
	}
	return (list->id == ID_O ? calc_id_o(tmp) : calc_id_g(tmp));
}

int						count_group_mtl(t_list_parser *list)
{
	int					i;
	t_list_parser		*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->id == ID_ERR_MTL && ft_strlen(tmp->data) > 1 &&
			tmp->data[0] == 'n')
			i++;
		tmp = tmp->next;
	}
	return (i);
}
