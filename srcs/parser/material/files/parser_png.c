/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:33:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 22:45:48 by xamartin         ###   ########lyon.fr   */
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
	// magic in hexa = "89 50 4E 47 0D 0A 1A 0A" need to change it
	if (!parser_image_header(file, ""))
		return (0);
	return (1);
}