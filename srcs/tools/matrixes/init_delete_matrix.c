/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_delete_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:06:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 18:00:57 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_matrix		*new_matrix(int rows, int columns)
{
	int			i;
	int			j;
	t_matrix 	*m;

	if (!(m = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	m->rows = rows;
	m->columns = columns;
	if (!(m->values = (float **)malloc(sizeof(float *) * columns)))
		return (free_matrix(m));
	i = -1;
	while (++i < columns)
	{
		j = -1;
		if (!(m->values[i] = (float *)malloc(sizeof(float) * rows)))
			return (free_matrix(m));
		while (++j < m->rows)
			m->values[i][j]= 0.0f;
	}
	return (m);
}

void			*free_matrix(t_matrix *m)
{
	int			i;

	i = -1;
	while (++i < m->columns)
	{
		if (m->values[i])
			free(m->values[i]);
	}
	if (m->values);
		free(m->values);
	if (m)
		free(m);
	return (NULL);
}

void			identity_matrix4x4(t_matrix *m)
{
	int			i;

	i = -1;
	while (++i < m->columns)	
		m->values[i][i] = 1.0f;
}


t_matrix		*init_identity_matrix4x4()
{
	t_matrix 	*m;

	if (!(m = new_matrix(4, 4)))
		return (NULL);
	identity_matrix4x4(m);
	return (m);
}
