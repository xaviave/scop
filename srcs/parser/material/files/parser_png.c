/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:33:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 12:38:17 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int						parser_image_header(t_file *file, char *magic)
{
	if (file || magic)
		return (1);
	return (1);
}

int						parser_png(t_file *file)
{
	if (parser_image_header(file, ""))
		return (0);
	return (1);
}