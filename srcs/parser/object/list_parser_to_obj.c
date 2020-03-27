/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:08:17 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/27 19:52:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 0;
	print_obj(obj);
	// need to check if there's vertexes and faces
	// need to check all the v - vn - vt ids in lines and faces
	// if s != 0 in groups or objects, need vn ids
	return (err);
}

int					list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	int				o_id;
	int				g_id;
	t_list_parser	*tmp;
	void			(*f[7])(t_obj *, char *, int, int);

	init_parser_obj_ptr(f);
	o_id = -1;
	g_id = -1;
	tmp = list;
	while (tmp)
	{
		if (tmp->id == ID_G || tmp->id == ID_O)
        {
			if (tmp->id == ID_O)
				o_id = obj->len_objects;
			else
				g_id = obj->len_groups;
			tmp->id == ID_G ? \
			parser_g(obj, tmp->data, o_id) : parser_o(obj, tmp->data);
        }
		else if (tmp->id < ID_G)
			f[tmp->id](obj, tmp->data, o_id, g_id);
		tmp = tmp->next;
	}
	return (check_obj(obj));
}