/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:30:45 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/03 18:48:32 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	init_texture_option(t_texture_option *new)
{
	ft_memset(new, 0, sizeof(t_texture_option));
	new->blendu = 1;
	new->blendv = 1;
	new->cc = 1;
	new->imfchan = -1; // mean no imfchan
	// louis go to scop.h:265 if you want explanation of malloc | it is to be a tmp[x] tab
	if (!(new->mm = (double *)malloc(sizeof(double) * 2)))
		return ;
	if (!(new->o = (double *)malloc(sizeof(double) * 3)))
		return ;
	if (!(new->s = (double *)malloc(sizeof(double) * 3)))
		return ;
	if (!(new->t = (double *)malloc(sizeof(double) * 3)))
		return ;
	new->mm[1] = 1;
}