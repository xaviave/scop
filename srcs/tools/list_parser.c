/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:54:29 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:55:02 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"
#include "../../includes/parser.h"

static t_list_parser		*new_list_parser(char *raw_data,
	t_parser_option *opt)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL);
	if (!(new->data = ft_strtrim(raw_data)))
	{
		free(&new);
		new = NULL;
		return (NULL);
	}
	new->id = (opt->parsing_type == P_OBJ) ?
		  define_id_obj(raw_data, opt) : define_id_mtl(raw_data);
	new->next = NULL;
	opt->list_parser_len++;
	return (new);
}

void						add_list_parser(t_list_parser **list,
		char *raw_data, t_parser_option *opt, t_addr **addr)
{
	t_list_parser			*new;
	static t_list_parser	*last;

	if (!(new = new_list_parser(raw_data, opt)))
	{
		ft_strdel(&raw_data);
		handle_error_parser("Error during memory allocation.", addr);
	}
	if (!(*list))
	{
		*list = addr_add(new, M_L_PAR_, addr);
		last = *list;
	}
	else
	{
		last->next = new;
		last = last->next;
	}
}

int							list_parser_len(t_list_parser **list)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
