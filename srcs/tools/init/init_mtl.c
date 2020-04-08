/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:07:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 00:17:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/tools.h"

void					init_mtl(t_mtl *mtl, int id, int nb_args, int nb_group)
{
	ft_memset(mtl, 0, sizeof(t_mtl));
	mtl->id = id;
    mtl->nb_args = nb_args;
	mtl->nb_groups = nb_group;
    // don't forget to set mtl->name with good value.
	ft_printf("nb_groups not set need to count newmtl in file | %d\n", nb_group);
	if (!(mtl->groups = (char **)malloc(sizeof(char *) * nb_group)))
		return ;
}
