/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:30:45 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:05:21 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

int			init_texture_option(t_texture_option *new)
{
	ft_memset(new, 0, sizeof(t_texture_option));
	new->blendu = 1;
	new->blendv = 1;
	new->cc = 1;
	new->imfchan = -1;
	if (!(new->mm = (double *)ft_memalloc(sizeof(double) * 2)))
		return (0);
	if (!(new->o = (double *)ft_memalloc(sizeof(double) * 3)))
		return (0);
	if (!(new->s = (double *)ft_memalloc(sizeof(double) * 3)))
		return (0);
	if (!(new->t = (double *)ft_memalloc(sizeof(double) * 3)))
		return (0);
	new->mm[1] = 1;
	return (1);
}
