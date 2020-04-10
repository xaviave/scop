/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mipmap_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:19:54 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 12:37:51 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int						parser_mpc(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}

int						parser_mps(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}

int						parser_mpb(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}