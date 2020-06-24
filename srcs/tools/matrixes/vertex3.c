/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:21:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:27 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void			vertex3_mul_cross(float r[3],
	float const a[3], float const b[3])
{
	r[0] = a[1] * b[2] - a[2] * b[1];
	r[1] = a[2] * b[0] - a[0] * b[2];
	r[2] = a[0] * b[1] - a[1] * b[0];
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
