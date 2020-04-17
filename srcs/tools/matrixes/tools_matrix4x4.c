/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_matrix4x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 22:51:01 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 22:55:18 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

float			degree_to_radians(float angle)
{
	return (angle * (180 / M_PI));
}

float			*transform_matrix4x4_to_float(t_matrix *m)
{
	int			i;
	float		*flat_data;
	
	i = -1;
	if (!(flat_data = (float *)malloc(sizeof(float) * 16)))
		return (NULL);
	while  (++i < 16)
		flat_data[i] = m->values[i / 4][i % 4];
	return (flat_data);
}
