/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_line_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 19:00:06 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 19:16:08 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int					check_int(char *raw_data, int *i, int neg)
{
	*i = pass_whitespace(raw_data, *i);
	if (neg && raw_data[*i] == '-')
	while (raw_data[*i++])
		if (raw_data[*i] < '0' && raw_data[*i] > '9')
			return (0);
	return (1);
}

static int					check_double(char *raw_data, int *i)
{
	*i = pass_whitespace(raw_data, *i);
	if (!check_int(raw_data, i, 1))
		return (0);
	if (raw_data[*i] != '.')
		return (1);
	return ((check_int(raw_data, i, 0)) ? 1 : 0);
}

static int					check_str(char *raw_data, int *i)
{
	int						tmp;

	tmp = *i;
	*i = pass_whitespace(raw_data, *i);
	return ((tmp != *i) ? 1 : 0);
}

/*
** type:	0 = int
**			1 = double
**			2 = str
*/

int							check_line(char *raw_data, int nb_args[2], int type)
{
	int						i;
	int						tmp;

	tmp = -1;
	while (raw_data[++i] && ++tmp < nb_args[1])
	{
		if ((!type && check_int(raw_data, &i, 1)) ||
			(type == 1 && check_double(raw_data, &i)) ||
			(type == 2 && check_str(raw_data, &i)))
			return (0);
		if (i + 1 && raw_data[i] != ' ' && raw_data[i] != '\t') // next char after an entity must be a whitespace
			return (0);
	}	
	return ((tmp < nb_args[0] || tmp > nb_args[1]) ? 0 : 1);
}