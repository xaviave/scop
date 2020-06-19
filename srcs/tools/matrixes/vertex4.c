/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:21:44 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 20:21:48 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

float			vertex4_mul_inner(float a[4], float b[4])
{
	float		p;
	int			i;

	p = 0.0f;
	i = -1;
	while (++i < 4)
		p += b[i] * a[i];
	return p;
}

void			vertex4_row_matrix4x4(float r[4], t_matrix *m, int i)
{
	int			k;

	k = -1;
	while (++k < 4)
		r[k] = m->values[k][i];
}
