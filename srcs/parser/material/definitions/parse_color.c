/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:15:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:11 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

/*
** Transform xyz color type to rgb using a matrix
** type define the value of the matrix, each colors have different matrix value
** type = [x = 0, y = 1, z = 2]
**
** R =  3.2404542*X - 1.5371385*Y - 0.4985314*Z
** G = -0.9692660*X + 1.8760108*Y + 0.0415560*Z
** B =  0.0556434*X - 0.2040259*Y + 1.0572252*Z
*/

static void					matrix_values(short type, double values[3])
{
	if (!type)
	{
		values[0] = 3.2406;
		values[1] = -1.5372;
		values[2] = -0.4986;
	}
	else if (type == 1)
	{
		values[0] = -0.9689;
		values[1] = 1.8758;
		values[2] = 0.0415;
	}
	else
	{
		values[0] = 0.0557;
		values[1] = -0.2040;
		values[2] = 1.0570;
	}
}

static double				gradient_corrector(double c)
{
	if (fabs(c) <= 0.0031308)
		c = 12.92 * c;
	else
		c = (1.055 * pow(c, 0.416)) - 0.055;
	return (c);
}

static double				xyz_to_rgb(double x, double y, double z, short type)
{
	double					c;
	double					matrix[3];

	ft_memset(&matrix, 0, sizeof(matrix));
	matrix_values(type, matrix);
	c = matrix[0] * x + matrix[1] * y + matrix[2] * z;
	return (gradient_corrector(c));
}

static int					pass_header_xyz(char *raw_data)
{
	int						i;

	i = -1;
	while (raw_data[++i])
		if (raw_data[i] == 'z')
			return (i + 1);
	return (i);
}

void						parse_color(t_color *color, char *raw_data, int xyz)
{
	int						i;
	size_t					data_len;

	data_len = ft_strlen(raw_data);
	i = (xyz) ? pass_header_xyz(raw_data) : 2;
	color->r = ft_atof(&raw_data[i]);
	i = pass_whitespace_str(i, raw_data);
	if ((size_t)i != data_len)
		color->g = ft_atof(&raw_data[i]);
	else
		color->g = color->r;
	i = pass_whitespace_str(i, raw_data);
	if ((size_t)i != data_len)
		color->b = ft_atof(&raw_data[i]);
	else
		color->b = color->r;
	if (xyz)
	{
		color->r = xyz_to_rgb(color->r, color->g, color->b, 0);
		color->g = xyz_to_rgb(color->r, color->g, color->b, 1);
		color->b = xyz_to_rgb(color->r, color->g, color->b, 2);
	}
}
