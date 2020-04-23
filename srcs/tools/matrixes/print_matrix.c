/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 10:18:04 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/22 19:02:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void			print_matrix(t_matrix *m, char *str)
{
	int			i;
	int			j;

	i = -1;
	dprintf(1, "\n------------------------------------------------------------------\n%s\n", str);
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->columns)
		{
			if (j == 0)
				dprintf(1, "[");
			else
				dprintf(1, "\t");
			dprintf(1, "%10f", m->values[i][j]);
			if (j == m->columns - 1)
				dprintf(1, "]\n");
		}
	}
	dprintf(1, "------------------------------------------------------------------\n");

}

void			print_mat4x4(mat4x4 m, char *str)
{
	int			i;
	int			j;

	i = -1;
	dprintf(1, "\n------------------------------------------------------------------\n%s\n", str);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j == 0)
				dprintf(1, "[");
			else
				dprintf(1, "\t");
			dprintf(1, "%10f", m[i][j]);
			if (j == 3)
				dprintf(1, "]\n");
		}
	}
	dprintf(1, "------------------------------------------------------------------\n");

}
