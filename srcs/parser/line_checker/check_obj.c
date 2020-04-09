/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:17:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 22:07:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int					check_vertexes(char *raw_data)
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
		if (!ft_isdigit(raw_data[i]) &&
			(raw_data[i] == '.' && ++p > 1 ) && (raw_data[i] == '-' && ++l > 1))
			return (0);
	}
	return ((i != (int)ft_strlen(raw_data) || nb_vertexes < 3) ? 0 : 1);
}

static int					check_ids_group(char *raw_data, int nb_delim)
{
	int						i;
	int						delim;

	i = -1;
	delim = 0;
	while (raw_data[++i] && raw_data[i] != ' ' && raw_data[i] != '\t')
	{
		if (raw_data[i] == '/')
			delim++;
		else if (!ft_isdigit(raw_data[i]))
			return (0);
	}
	return (delim == nb_delim);
}

static int					check_lines_faces(char *raw_data)
{
	int						i;
	int						len;
	int						nb_id;
	int						nb_delim;

	// ft_printf("add a param to differenciate lines and faces\n");
	i = 0;
	len = ft_strlen(raw_data);
	nb_delim = count_char(&raw_data[i], '/');
	if (nb_delim == 3 || nb_delim == 4)
		nb_delim = 1;
	else if (nb_delim == 6 || nb_delim == 8)
		nb_delim = 2;
	else if (nb_delim)
		return (0);
	nb_id = 0;
	while (i != len && ++nb_id < 5)
	{
		if (!check_ids_group(&raw_data[i], nb_delim))
			return (0);
		i = pass_whitespace_str(i, raw_data);
	}
	return ((nb_id < 3 || i != len) ? 0 : 1);
}

static int					dispatch_by_header(char *raw_data, t_parser_option *opt)
{
	int						i;
	int						nb_args[2];
	char					tmp[3];

	nb_args[0] = 1;
	nb_args[1] = 1;
	i = pass_whitespace_str(0, raw_data);
	ft_bzero(tmp, 3);
	ft_strncpy(tmp, &raw_data[pass_whitespace(0, raw_data)], 2);
	if ((opt->data_len > 8 && (!ft_strcmp(tmp, "us") ||
		!ft_strcmp(tmp, "mt"))) || tmp[0] == '#' || tmp[0] == 's')
		return (1);
	else if (!ft_strcmp(tmp, "vt") || !ft_strcmp(tmp, "vn") ||
		!ft_strcmp(tmp, "vp") || (tmp[0] == 'v' &&
		(tmp[1] == ' ' || tmp[1] == '\t')))
	{
		nb_args[1] = 3;
		return (check_line(&raw_data[i], nb_args, 1) && check_vertexes(&raw_data[i]));
	}
	else if (ft_strstr(tmp, "g") || ft_strstr(tmp, "o"))
		return check_line_str(raw_data, opt->data_len, 1); // not done yet
	else if (ft_strstr(tmp, "l") || ft_strstr(tmp, "f"))
	{
		nb_args[0] = 3;
		nb_args[1] = 4;
		// put str option if '/' in raw_data
		return (check_line(&raw_data[i], nb_args, 2) && check_lines_faces(&raw_data[i]));
	}
	return (0);
}

/*
** the tinniest line is a texture define: "s 1"
*/

int						check_obj_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len == 2 && raw_data[0] == 'g')
		return (1);
    return (opt->data_len > 2 ? dispatch_by_header(raw_data, opt) : 0);
}
