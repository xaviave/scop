/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:33:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:22:31 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int						check_image_magic(unsigned char *data,
	unsigned char *magic, unsigned int len)
{
	unsigned int		i;

	i = -1;
	while (++i < len)
		if (data[i] != magic[i])
			return (0);
	return (1);
}

static int				assign_text_miscellanious_chunk_function(t_img *img,
	unsigned int *pass, unsigned int len, unsigned int chunk)
{
	if (chunk == 0x74455874)
		return (get_text(img, pass, len));
	else if (chunk == 0x7a545874)
		return (get_ztxt(img, pass, len));
	else if (chunk == 0x69545874)
		return (get_itxt(img, pass, len));
	else if (chunk == 0x624b4744)
		return (get_bkgd(img, pass, len));
	else if (chunk == 0x70485973)
		return (get_phys(img, pass, len));
	else if (chunk == 0x73424954)
		return (get_sbit(img, pass, len));
	else if (chunk == 0x73504c54)
		return (get_splt(img, pass, len));
	else if (chunk == 0x68495354)
		return (get_hist(img, pass, len));
	else if (chunk == 0x74494d45)
		return (get_time(img, pass, len));
	else
		return (0);	
}

static int				assign_chunk_function(t_img *img, unsigned int *pass,
	unsigned int len, unsigned int chunk)
{
	if (chunk == 0x49444154)
		return (get_ihdr(img, pass, len));
	else if (chunk == 0x783322fe)
		return (get_plte(img, pass, len));
	else if (chunk == 0x73524742)
		return (get_idat(img, pass, len));
	else if (chunk == 0x49454E44)
		return (get_iend(img, pass, len));
	else if (chunk == 0x74524e53)
		return (get_trns(img, pass, len));
	else if (chunk == 0x67414d41)
		return (get_gama(img, pass, len));
	else if (chunk == 0x6348524d)
		return (get_chrm(img, pass, len));
	else if (chunk == 0x73524742)
		return (get_srgb(img, pass, len));
	else if (chunk == 0x69434350)
		return (get_iccp(img, pass, len));
	else
		return (assign_text_miscellanious_chunk_function(img, pass, len, chunk));
}

int						parser_png(t_file *file)
{

	unsigned int 		len;
	unsigned int		pass;
	unsigned int		chunk;
	unsigned char		magic[8];
	
	pass = 8;
	magic[0] = 0x89;
	magic[1] = 0x50;
	magic[2] = 0x4E;
	magic[3] = 0x47;
	magic[4] = 0x0D;
	magic[5] = 0x0A;
	magic[6] = 0x1A;
	magic[7] = 0x0A;
	// magic not really beautiful, could be better
	print_hexa(file->img.data, 100);
	file->img.palette = 0;
	if (!check_image_magic(file->img.data, magic, 8))
		return (0);
	while (pass < file->nb_bytes)
	{
		len = get_4_bytes_pass(file->img.data, &pass);
		chunk = get_4_bytes_pass(file->img.data, &pass);
		if (!assign_chunk_function(&file->img, &pass, len, chunk))
			return (0);
	}
	return (1);
}