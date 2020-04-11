/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_compiled_procedural_texture.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:18:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/11 18:44:17 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int						parser_cxc(t_file *file)
{
	unsigned char		magic[1];
	
	magic[0] = 0x89;
	// not really beautiful, could be better
	print_hexa(file->img.data, 100);
	if (!check_image_magic(file->img.data, magic, 1) ||
		!parser_image_header(&file->img, 8))
		return (0);
	return (1);
}

int						parser_cxs(t_file *file)
{
	unsigned char		magic[1];
	
	magic[0] = 0x89;
	// not really beautiful, could be better
	print_hexa(file->img.data, 100);
	if (!check_image_magic(file->img.data, magic, 1) ||
		!parser_image_header(&file->img, 8))
		return (0);
	return (1);
}

int						parser_cxb(t_file *file)
{
	unsigned char		magic[1];
	
	magic[0] = 0x89;
	// not really beautiful, could be better
	print_hexa(file->img.data, 100);
	if (!check_image_magic(file->img.data, magic, 1) ||
		!parser_image_header(&file->img, 8))
		return (0);
	return (1);
}