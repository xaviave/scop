/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:21:16 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 20:21:19 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void			vertex3_mul_cross(float r[3],
	float const a[3], float const b[3])
{
	r[0] = a[1]*b[2] - a[2]*b[1];
	r[1] = a[2]*b[0] - a[0]*b[2];
	r[2] = a[0]*b[1] - a[1]*b[0];
}

void			vertex3_sub(float r[3], float const a[3], float const b[3])
{
	int			i;

	i = -1;
	while (++i < 3)
		r[i] = a[i] - b[i];
}

void			vertex3_add(float r[3], float const a[3], float const b[3])
{
	int			i;

	i = -1;
	while (++i < 3)
		r[i] = a[i] + b[i];
}

void			vertex3_mul_float(float r[3], float const a[3], float const b)
{
	int			i;

	i = -1;
	while (++i < 3)
		r[i] = a[i] * b;
}

float			vertex3_mul_inner(float const a[3], float const b[3])
{
	float		p;
	int			i;

	i = -1;
	p = 0.0f;
	while (++i < 3)
		p += b[i] * a[i];
	return (p);
}

void			vertex3_scale(float r[3], float const v[3], float const s)
{
	int			i;

	i = -1;
	while (++i < 3)
		r[i] = v[i] * s;
}

void			vertex3_norm(float r[3], float const v[3])
{
	float		k;
	
	k = 1.0f / sqrtf(vertex3_mul_inner(v, v));
	vertex3_scale(r, v, k);
}
