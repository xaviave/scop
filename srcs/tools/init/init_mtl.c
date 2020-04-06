/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:07:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:30:48 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/tools.h"

void					init_mtl(t_mtl *mtl, int id, int nb_args)
{
	ft_memset(mtl, 0, sizeof(t_mtl));
	mtl->id = id;
    mtl->nb_args = nb_args;
}
