/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 22:43:57 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/21 23:16:37 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
