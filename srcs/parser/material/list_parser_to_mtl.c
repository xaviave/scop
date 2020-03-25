/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_mtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:11:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/25 23:48:53 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list)
{
	t_list_parser	*tmp;
	void			(*f[10])(t_mtl *, char *);


	init_parser_mtl_ptr(f);
	init_mtl_ptr(mtl, list);
	tmp = list;
}