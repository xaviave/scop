/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/22 21:41:04 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static int					define_id(char *raw_data)
{
	char					tmp[3];

	ft_bzero(tmp, 3);
	ft_strncpy(tmp, raw_data, 2);
	if (ft_strstr(tmp, "vt"))
		return (0);
	else if (ft_strstr(tmp, "vn"))
		return (1);
	else if (ft_strstr(tmp, "v"))
		return (2);
	else if (ft_strstr(tmp, "f"))
		return (3);
	else if (ft_strstr(tmp, "l"))
		return (4);
	else if (ft_strstr(tmp, "g"))
		return (6);
	else if (ft_strstr(tmp, "o"))
		return (7);
	else
		return (5);	
}

static t_list_parser		*new_list_parser(char *raw_data)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL);
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

int							list_parser_len(t_list_parser **list)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}