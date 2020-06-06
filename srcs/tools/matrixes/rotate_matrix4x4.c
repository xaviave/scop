/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix4x4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 22:46:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 22:47:57 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int 			rotate_matrix4x4_x(t_matrix *result,
	t_matrix *m, float angle)
{
	float		s;
	float		c;
	t_matrix	*tmp;

	s = sinf(angle);
	c = cosf(angle);
	if (!(tmp = init_identity_matrix4x4(NULL)))
	    return (0);
	tmp->values[1][1] = c;
	tmp->values[1][2] = s;
	tmp->values[2][1] = -s;
	tmp->values[2][2] = c;
	multiply_matrix4x4(result, m, tmp);
	free_matrix(tmp);
	return (1);
}

int 			rotate_matrix4x4_y(t_matrix *result,
	t_matrix *m, float angle)
{
	float		s;
	float		c;
	t_matrix	*tmp;

	s = sinf(angle);
	c = cosf(angle);
	if (!(tmp = init_identity_matrix4x4(NULL)))
	    return (0);
	tmp->values[0][0] = c;
	tmp->values[0][2] = s;
	tmp->values[2][0] = -s;
	tmp->values[2][2] = c;
	multiply_matrix4x4(result, m, tmp);
	free_matrix(tmp);
    return (1);
}

int 			rotate_matrix4x4_z(t_matrix *result,
	t_matrix *m, float angle)
{
	float		s;
	float		c;
	t_matrix	*tmp;

	s = sinf(angle);
	c = cosf(angle);
	if (!(tmp = init_identity_matrix4x4(NULL)))
	    return (0);
	tmp->values[0][0] = c;
	tmp->values[0][1] = s;
	tmp->values[1][0] = -s;
	tmp->values[1][1] = c;
	multiply_matrix4x4(result, m, tmp);
	free_matrix(tmp);
	return (1);
}
