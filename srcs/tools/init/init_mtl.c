/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:58:48 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:58:58 by ltoussai         ###   ########lyon.fr   */
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
