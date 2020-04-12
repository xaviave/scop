/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_chunk_idat_iend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:13:58 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:29:25 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				get_idat(t_img *img, unsigned int *pass,
	unsigned int len)
{
	ft_printf("get_idat: pass = %d | len = %d\n", *pass, len);
	ft_printf("color type = %d | bit depth = %d\n", img->color_type, img->bit_depth);
	return (0);
}

int			get_iend(t_img *img, unsigned int *pass,
	unsigned int len)
{
	ft_printf("get_iend: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}