/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/04/03 20:54:17 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static t_list_parser		*new_list_parser(char *raw_data,
	t_parser_option *opt)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL); // return NULL ? handled in previous call or better call handel_error_parse ?
	new->id = (opt->parsing_type == P_OBJ) ?
		define_id_obj(raw_data, opt) : define_id_mtl(raw_data, opt);
    new->data = ft_strtrim(raw_data);
	new->next = NULL;
	opt->list_parser_len++;
	return (new);
}

void                        add_list_parser(t_list_parser **list, char *raw_data,
	t_parser_option *opt)
{
	t_list_parser			*tmp;

	if (!(*list))
		*list = new_list_parser(raw_data, opt);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list_parser(raw_data, opt);
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