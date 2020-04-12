/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:07:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:38:12 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "tools.h"

void					init_mtl(t_mtl *mtl, int id,
	t_parser *parser, int nb_group)
{
	ft_memset(mtl, 0, sizeof(t_mtl));
	mtl->id = id;
    mtl->nb_args = parser->nb_args;
	mtl->path = parser->path[id];
	mtl->nb_groups = nb_group;
    // don't forget to set mtl->name with good value.
	if (!(mtl->groups = (char **)malloc(sizeof(char *) * nb_group)))
		return ;
}
