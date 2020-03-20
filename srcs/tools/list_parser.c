/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 21:46:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static int					define_id(char *raw_data)
{
	if (ft_strstr(raw_data, "vt"))
		return (0);
	else if (ft_strstr(raw_data, "vn"))
		return (1);
	else if (ft_strstr(raw_data, "vp"))
		return (2);
	else if (ft_strstr(raw_data, "v"))
		return (3);
	else if (ft_strstr(raw_data, "f"))
		return (4);
	else if (ft_strstr(raw_data, "l"))
		return (5);
	else
		return (6);	
}

static t_list_parser		*new_list_parser(char *raw_data)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		handle_error_parser("Error during memroy allocation");
	new->id = define_id(raw_data);
	new->data = raw_data;
	ft_printf("NEED TO CHECK IF LINE OK THANKS TO THE ID\n");
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

int							list_parser_len(t_list_parser **list)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	return (i);
}