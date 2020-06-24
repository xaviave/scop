/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_matrix4x4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:18:25 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:25 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void			multiply_matrix4x4(t_matrix *result, t_matrix *m,
	t_matrix *multiply)
{
	int			c;
	int			r;
	int			k;

	c = -1;
	while (++c < 4)
	{
		r = -1;
		while (++r < 4)
		{
			k = -1;
			result->values[c][r] = 0.0f;
			while (++k < 4)
				result->values[c][r] +=
					m->values[k][r] * multiply->values[c][k];
		}
	}
}

t_matrix		*scale_matrix4x4(double scale, t_matrix *m)
{
	int			i;
	int			j;
	t_matrix	*result;

	i = -1;
	if (!(result = new_matrix(4, 4)))
		return (NULL);
	while (++i < m->columns)
	{
		j = -1;
		while (++j < m->rows)
			m->values[i][j] *= scale;
	}
	return (result);
}

void			clear_matrix4x4(t_matrix *m)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m->values[i][j] = 0.0;
	}
}

void			translate_matrix4x4(t_matrix *m, float x, float y, float z)
{
	identity_matrix4x4(m);
	m->values[0][3] = x;
	m->values[1][3] = y;
	m->values[2][3] = z;
}

void			ortho_matrix4x4(t_matrix *m, float tab[6])
{
	m->values[0][0] = 2.0f / (tab[1] - tab[0]);
	m->values[0][1] = 0.0f;
	m->values[0][2] = 0.0f;
	m->values[0][3] = 0.0f;
	m->values[1][1] = 2.0f / (tab[3] - tab[2]);
	m->values[1][0] = 0.0f;
	m->values[1][2] = 0.0f;
	m->values[1][3] = 0.0f;
	m->values[2][2] = -2.0f / (tab[5] - tab[4]);
	m->values[2][0] = 0.0f;
	m->values[2][1] = 0.0f;
	m->values[2][3] = 0.0f;
	m->values[3][0] = -(tab[1] + tab[0]) / (tab[1] - tab[0]);
	m->values[3][1] = -(tab[3] + tab[2]) / (tab[3] - tab[2]);
	m->values[3][2] = -(tab[5] + tab[4]) / (tab[5] - tab[4]);
	m->values[3][3] = 1.0f;
}
