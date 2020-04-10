/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_compiled_procedural_texture.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:18:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 12:38:07 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int						parser_cxc(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}

int						parser_cxs(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}

int						parser_cxb(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}