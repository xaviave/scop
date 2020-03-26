/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:08:17 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/26 11:08:26 by xamartin         ###   ########lyon.fr   */
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
	// need to check if there's vertexes and faces or other things
	// need to check all the v - vn - vt ids in lines and faces
	return (err);
}

static void			define_groups_and_objects(t_obj *obj, t_list_parser *list)
{
    int             len_list;
	t_list_parser	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->id == ID_G || tmp->id == ID_O)
        {
		    len_list = len_list_parser_id(tmp);
			// need to add a value smoothing group
			tmp->id == ID_G ? \
			parser_g(obj, tmp->data, len_list) : \
			parser_o(obj, tmp->data, len_list);
        }
		tmp = tmp->next;
	}
}

int					list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	t_list_parser	*tmp;
	void			(*f[7])(t_obj *, char *);

	init_parser_obj_ptr(f);
	define_groups_and_objects(obj, list);
	tmp = list;
	while (tmp)
	{
		if (tmp->id < ID_G)
			f[tmp->id](obj, tmp->data);
		tmp = tmp->next;
	}
	return (check_obj(obj));
}