/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_line_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:51:19 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 18:00:52 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

/*
** if neg normal behavior else error if the number is negative
**and stop if a '.' is found
*/

static int					check_int(char *raw_data, int *i, int neg)
{
	*i = pass_whitespace(*i, raw_data);
	if (!neg && raw_data[*i] == '-')
		return (0);
	else if (raw_data[*i] == '-')
		*i = *i + 1;
	while (raw_data[*i] && raw_data[*i] != ' ' && raw_data[*i] != '\t')
	{
		if (neg && raw_data[*i] == '.')
			return (1);
		else if (!ft_isdigit(raw_data[*i]))
			return (0);
		*i = *i + 1;
	}
	return (1);
}

static int					check_double(char *raw_data, int *i)
{
	*i = pass_whitespace(*i, raw_data);
	if (!check_int(raw_data, i, 1))
		return (0);
	if (raw_data[*i] != '.')
		return (1);
	*i = *i + 1;
	return (check_int(raw_data, i, 0));
}

/*
** type:	0 = int
** 		1 = double
** 		2 = str dont use it need real parsing
*/

int							check_line(char *raw_data, int nb_args[2], int type)
{
	int						i;
	int						tmp;

	i = 0;
	tmp = 0;
	while (raw_data[i] && ++tmp <= nb_args[1])
	{
		if ((!type && !check_int(raw_data, &i, 1)) ||
			(type == 1 && !check_double(raw_data, &i)))
			return (0);
		i--;
		if (i + 1 && raw_data[i] != ' ' && raw_data[i] != '\t')
			break ;
	}
	return (tmp >= nb_args[0] || tmp < nb_args[1]);
}
