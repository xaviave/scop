/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:33:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/11 19:07:51 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int						check_image_magic(unsigned char *data, unsigned char *magic, int len)
{
	int					i;

	i = -1;
	while (++i < len)
		if (data[i] != magic[i])
			return (0);
	return (1);
}

void printb(unsigned int v) {
    unsigned int i, s = 1<<((sizeof(v)<<3)-1); // s = only most significant bit at 1
    for (i = s; i; i>>=1)
		ft_printf("%d", v & i || 0 );
	ft_printf("\n");
}

unsigned int			get_4_bytes(unsigned char *data)
{
	unsigned char		o[4];

	ft_memcpy(o, data, 4);
	return ((unsigned int)(o[0] << 24) + (o[1] << 16) + (o[2] << 8) + o[3]);
}

int						parser_image_header(t_img *img, int pass)
{
	// values are just for png for now
	if (get_4_bytes(&img->data[pass]) != 0x0D ||
		get_4_bytes(&img->data[pass + 4]) != 0x49484452)
		return (0);
	img->width = get_4_bytes(&img->data[pass + 8]);
	img->heigth = get_4_bytes(&img->data[pass + 12]);
	if (!img->width || !img->heigth)
		return (0);
	img->bit_depth = img->data[pass + 16];
	if (img->bit_depth != 1 && img->bit_depth != 2 &&
		img->bit_depth != 4 && img->bit_depth != 8 && img->bit_depth != 16)
		return (0);
	img->color_type = img->data[pass + 17];
	if (!img->color_type && img->color_type != 2 &&
		img->color_type != 3 && img->color_type != 4 && img->color_type != 6)
		return (0);
	img->compression = img->data[pass + 18];
	img->filter = img->data[pass + 19];
	if (img->compression || img->filter)
		return (0);
	img->interlace = img->data[pass + 19];
	if (img->interlace != 0 && img->interlace != 1)
		return (0);
	return (1);
}

int						parser_png(t_file *file)
{
	unsigned char		magic[8];
	
	magic[0] = 0x89;
	magic[1] = 0x50;
	magic[2] = 0x4E;
	magic[3] = 0x47;
	magic[4] = 0x0D;
	magic[5] = 0x0A;
	magic[6] = 0x1A;
	magic[7] = 0x0A;
	// not really beautiful, could be better
	print_hexa(file->img.data, 100);
	if (!check_image_magic(file->img.data, magic, 8) ||
		!parser_image_header(&file->img, 8))
		return (0);
	return (1);
}