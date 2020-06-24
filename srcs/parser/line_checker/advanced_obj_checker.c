/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_obj_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:50:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:06 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int					return_vertexes(char tmp[3], int i, int nb_v)
{
	int						check_nb_v;

	check_nb_v = 2;
	return (i < (int)ft_strlen(tmp) || nb_v < check_nb_v || nb_v > 4 ? 0 : 1);
}

int							check_vertexes(char *raw_data, char tmp[3])
{
	int						i;
	int						p;
	int						l;
	int						nb_vertexes;

	i = -1;
	p = 0;
	l = 0;
	nb_vertexes = 0;
	while (raw_data[++i])
	{
		if (raw_data[i] == ' ' || raw_data[i] == '\t')
		{
			p = 0;
			l = 0;
			nb_vertexes++;
			i = pass_whitespace(i, raw_data);
		}
		if ((!ft_isdigit(raw_data[i]) &&
			raw_data[i] != '.' && raw_data[i] != '-' && raw_data[i] != '\0') ||
			(raw_data[i] == '.' && ++p > 1) || (raw_data[i] == '-' && ++l > 1))
			return (0);
	}
	return (return_vertexes(tmp, i, nb_vertexes));
}

static int					check_ids_group(char *raw_data)
{
	int						i;
	int						delim;

	i = pass_whitespace(0, raw_data);
	delim = 0;
	while (raw_data[++i] && raw_data[i] != ' ' && raw_data[i] != '\t')
	{
		if (raw_data[i] == '/')
			delim++;
		else if (!ft_isdigit(raw_data[i]))
			return (0);
	}
	return (1);
}

int							check_lines_faces(char *raw_data,
	int *nb_args, int len)
{
	int						i;
	int						nb_id;
	int						nb_delim;

	i = 1;
	len = ft_strlen(raw_data);
	nb_delim = count_char(&raw_data[i], '/');
	if (nb_delim == nb_args[0] || nb_delim == nb_args[1])
		nb_delim = 1;
	else if (nb_delim == (nb_args[0] * 2) || nb_delim == (nb_args[1] * 2))
		nb_delim = 2;
	else if (nb_delim)
		return (0);
	nb_id = 0;
	while (i != len && ++nb_id <= nb_args[1])
	{
		if (!check_ids_group(&raw_data[i]))
			return (0);
		i = pass_whitespace_str(i, raw_data);
	}
	i = pass_whitespace(i, raw_data);
	return ((nb_id < nb_args[0] || i != len) ? 0 : 1);
}
