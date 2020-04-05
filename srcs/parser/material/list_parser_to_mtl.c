/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_mtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:11:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:27:43 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int			check_mtl(t_mtl *mtl)
{
	ft_printf("id = %d | %s = %name\n", mtl->id, mtl->name);
	print_mtl(mtl);
	return (1);
}

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list)
{
	t_list_parser	*tmp;
	void			(*f[13])(t_mtl *, char *);

	tmp = list;
	init_parser_mtl_ptr(f);
	while (tmp)
	{
		ft_printf("id = %d | %s\n", tmp->id, tmp->data);
		f[tmp->id](mtl, tmp->data);
		tmp = tmp->next;
	}
	return (check_mtl(mtl));
}