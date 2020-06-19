/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:02:05 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:06:33 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 0;
	if (obj)
		return (1);
	return (1);
}

int					list_parser_to_obj(t_obj *obj, t_list_parser *list,
		t_addr **addr)
{
	int				o_id;
	int				g_id;
	t_list_parser	*tmp;
	int				(*f[7])(t_obj *, char *, int, int);

	init_parser_obj_ptr(f);
	o_id = -1;
	g_id = -1;
	tmp = list;
	while (tmp)
	{
		if (tmp->id == ID_G || tmp->id == ID_O)
		{
			o_id = tmp->id == ID_O ? obj->len_objects : o_id;
			g_id = tmp->id != ID_O ? obj->len_groups : g_id;
			if (!(tmp->id == ID_G ?
			parser_g(obj, tmp->data, o_id) : parser_o(obj, tmp->data)))
				handle_error_parser("Error during memory allocation.", addr);
		}
		else if (tmp->id < ID_G && !(f[tmp->id](obj, tmp->data, o_id, g_id)))
			handle_error_parser("Error during memory allocation.", addr);
		tmp = tmp->next;
	}
	return (check_obj(obj));
}
