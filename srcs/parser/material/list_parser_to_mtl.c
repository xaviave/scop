/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_mtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:11:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/31 22:51:50 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

static int			check_mtl(t_mtl *mtl)
{
	ft_printf("id = %d | %s = %name\n", mtl->id, mtl->name);
	// print_mtl(mtl);
	return (1);
}

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list)
{
	t_list_parser	*tmp;
	void			(*f[11])(t_mtl *, char *);


	init_parser_mtl_ptr(f);
	ft_printf("NEED TO FINISH THE MTL ARCHITECTURE AND OPTION\nNEXT START PARSING\n");
	tmp = list;
	while (tmp)
	{
		ft_printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
	return (check_mtl(mtl));
}