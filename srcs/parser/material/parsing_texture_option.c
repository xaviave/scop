/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 12:18:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 20:37:49 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

static void				init_texture_option(t_texture_option *new)
{
	ft_memset(new, 0, sizeof(t_texture_option));
	new->blendu = 1;
	new->blendv = 1;
	new->cc = 1;
	new->imfchan = -1; // mean no imfchan
	new->mm[1] = 1;
}

void					parsing_texture_option(t_texture_option *new, char *raw_data, short type)
{
	init_texture_option(new);
}