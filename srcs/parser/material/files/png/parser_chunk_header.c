/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_chunk_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:35:44 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:38:37 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int				check_ihdr(t_img *img)
{
	// check http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html
	if (img->bit_depth != 1 && img->bit_depth != 2 &&
		img->bit_depth != 4 && img->bit_depth != 8 && img->bit_depth != 16)
		return (0);
	if (!img->color_type && img->color_type != 2 &&
		img->color_type != 3 && img->color_type != 4 && img->color_type != 6)
		return (0);
	if ((img->bit_depth == 1 && (img->color_type == 2 ||
		img->color_type == 4 || img->color_type == 6)) ||
		(img->bit_depth == 2 && (img->color_type == 2 ||
		img->color_type == 4 || img->color_type == 6)) ||
		(img->bit_depth == 4 && (img->color_type == 2 ||
		img->color_type == 4 || img->color_type == 6)) ||
		(img->bit_depth == 16 && (img->color_type == 3)))
		return (0);
	return (1);
}

int						get_ihdr(t_img *img, unsigned int *pass,
	unsigned int len)
{
	unsigned int		crc;

	// values are just for png for now
	ft_printf("get_ihdr: pass = %d | len = %d\n", *pass, len);
	if (len != 0x0D)
		return (0);
	img->width = get_4_bytes_pass(img->data, pass);
	img->heigth = get_4_bytes_pass(img->data, pass);
	if (!img->width || !img->heigth)
		return (0);
	img->bit_depth = img->data[*pass];
	img->color_type = img->data[++(*pass)];
	img->compression = img->data[++(*pass)];
	img->filter = img->data[++(*pass)];
	if (img->compression || img->filter)
		return (0);
	img->interlace = img->data[++(*pass)];
	if (img->interlace != 0 && img->interlace != 1)
		return (0);
	*pass += 1;
	crc = get_4_bytes_pass(img->data, pass);
	ft_printf("check the crc = %x\n", crc);
	return (check_ihdr(img));
}
