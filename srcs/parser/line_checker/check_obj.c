/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:17:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 19:44:08 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int					check_color(char *raw_data)
{
	int						tmp;

	tmp = ft_atoi(raw_data);
	if (tmp == 0 || tmp == 1)
		return (1);
	return (0);
}

static int					check_vertexes(char *raw_data)
{
	int						i;
	int						len;

	len = ft_strlen(raw_data);
	if (!check_color(&raw_data[i]))
		return (0);
	i = pass_whitespace_number(i, raw_data);
	if (i != len && !check_color(&raw_data[i]))
		return (0);
	i = pass_whitespace_number(i, raw_data);
	if (i != len && !check_color(&raw_data[i]))
		return (0);
	return (1);
}

static int					check_ids_group(char *raw_data, int nb_delim)
{
	int						i;
	int						delim;

	i = -1;
	delim = 0;
	while (raw_data[++i])
	{
		if (raw_data[i] == '/')
			delim++;
		else if (!ft_isdigit(raw_data[i]))
			return (0);
	}
	return ((delim == nb_delim) ? 1 : 0);
}

static int					check_lines_faces(char *raw_data)
{
	int						i;
	int						len;
	int						nb_delim;

	len = ft_strlen(raw_data);
	nb_delim = count_char(&raw_data[1], '/');
	if (!nb_delim)
		nb_delim = 0;
	else if (nb_delim == 3 || nb_delim == 4)
		nb_delim = 1;
	else if (nb_delim == 6 || nb_delim == 8)
		nb_delim = 2;
	else
		return (0);
	if (!check_ids_group(&raw_data[0], nb_delim))
		return (0);
	i = pass_whitespace_number(0, raw_data);
	if (i != len && !check_ids_group(&raw_data[i], nb_delim))
		return (0);
	i = pass_whitespace_number(i, raw_data);
	if (i != len && !check_ids_group(&raw_data[i], nb_delim))
		return (0);
	i = pass_whitespace_number(i, raw_data);
	if (i != len && !check_ids_group(&raw_data[i], nb_delim))
		return (0);
	return (1);
}

static int					dispatch_by_header(char *raw_data, t_parser_option *opt)
{
	int						i;
	int						nb_args[2];
	char					tmp[3];

	nb_args[0] = 1;
	nb_args[1] = 1;
	i = pass_whitespace_str(raw_data, 0);
	ft_bzero(tmp, 3);
	ft_strncpy(tmp, &raw_data[pass_whitespace_str(0, raw_data)], 2);
	ft_printf("tmp = %s | str = %s\n", tmp, raw_data);
	if (opt->data_len > 8 && (!ft_strcmp(tmp, "us") ||
		!ft_strcmp(tmp, "mt")))
		return (1);
	else if (!ft_strcmp(tmp, "vt") || !ft_strcmp(tmp, "vn") ||
		!ft_strcmp(tmp, "vp") || (tmp[0] == 'v' &&
		(tmp[1] == ' ' || tmp[1] == '\t')))
	{
		nb_args[1] = 3;
		return (check_line(&raw_data[i], nb_args, 1) && check_vertexes(&raw_data[i]));
	}
	else if (ft_strstr(tmp, "g") || ft_strstr(tmp, "o"))
		return check_line_str(raw_data, opt->data_len, 1);
	else if (ft_strstr(tmp, "l") || ft_strstr(tmp, "f"))
	{
		nb_args[0] = 3;
		nb_args[1] = 4;
		// put str option if '/' in raw_data
		return (check_line(&raw_data[i], nb_args, 2) && check_lines_faces(&raw_data[i]));
	}
	else if (ft_strstr(tmp, "#") || ft_strstr(tmp, "s"))
		return (1);
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
