/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_chunk_palette.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:38:00 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:26:01 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
static int			check_plte(t_img *img)
{
	if (img->palette > 1 || img->color_type == 0 || img->color_type == 4)
		return (0);
	return (1);
}
int					get_plte(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_plte: pass = %d | len = %d\n", *pass, len);
	return (0);
	img->palette++;
	return (check_plte(img));
}

int					get_splt(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_splt: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}

int					get_hist(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_hist: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}
