/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_mtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:11:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:33:58 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			check_mtl(t_mtl *mtl)
{
	// if (mtl)
	// 	return (1);
	print_mtl(mtl);
	return (1);
}

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list,
        t_addr **addr)
{
	int				group_id;
	t_list_parser	*tmp;
    int 			(*f[13])(t_mtl *, char *, int);

	group_id = -1;
	tmp = list;
	init_parser_mtl_ptr(f);
	while (tmp)
	{
		ft_printf("id = %d | %s\n", tmp->id, tmp->data);
		// trim applied before so first char is either 'n' either '#'
		if (tmp->id == ID_ERR_MTL && tmp->data[0] == 'n')
			group_id++;
		if (!(f[tmp->id](mtl, tmp->data, group_id)))
		    handle_error_parser("Error during memory allocation.", addr);
		tmp = tmp->next;
	}
	return (check_mtl(mtl));
}