/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:58:48 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:23 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void					init_mtl(t_mtl *mtl, int id,
	t_parser *parser, int nb_group)
{
	int					tmp;

	tmp = mtl->nb_args;
	ft_memset(mtl, 0, sizeof(t_mtl));
	mtl->id = id;
	mtl->nb_args = tmp;
	mtl->path = parser->path[id];
	mtl->nb_groups = nb_group;
	if (!(mtl->groups = (char **)malloc(sizeof(char *) * nb_group)))
		return ;
}
