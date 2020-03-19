/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/19 23:28:46 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "includes/parser.h"

static int					define_id(char *raw_data)
{
	if (ft_strstr(raw_data, "vt"))
		return (1);
	else if (ft_strstr(raw_data, "vn"))
		return (2);
	else if (ft_strstr(raw_data, "vp"))
		return (3);
	else if (ft_strstr(raw_data, "v"))
		return (4);
	else if (ft_strstr(raw_data, "f"))
		return (5);
	else if (ft_strstr(raw_data, "l"))
		return (6);
	else
		return (0);	
}

static t_list_parser		*new_list_parser(char *raw_data)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		handle_error_parser("Error during memroy allocation");
	new->id = define_id(raw_data);
	new->data = raw_data;
	new->next = NULL;
	return new;
}

void                        add_list_parser(t_list_parser **list, char *raw_data)
{
	t_list_parser			*tmp;

	if (!(*list))
		*list = new_list_parser(raw_data);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list_parser(raw_data);
	}
}