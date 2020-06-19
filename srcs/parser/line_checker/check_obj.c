/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:53:27 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 18:06:21 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int			dispatch_f_l_g_o(char *raw_data, int i,
		char tmp[3], int nb_args[2])
{
	if ((tmp[0] == 'g' || tmp[0] == 'o') &&
		(tmp[1] == ' ' || tmp[1] == '\t'))
		return (check_line_str(raw_data, (int)ft_strlen(raw_data), 1));
	else if ((tmp[0] == 'f' || tmp[0] == 'l') &&
		(tmp[1] == ' ' || tmp[1] == '\t'))
	{
		nb_args[0] = (tmp[0] == 'f') ? 3 : 2;
		nb_args[1] = (tmp[0] == 'f') ? 4 : 3;
		return (check_lines_faces(&raw_data[i], nb_args,
				(int)ft_strlen(raw_data)));
	}
	return (0);
}

static int			dispatch_by_header(char *raw_data,
	t_parser_option *opt, t_status_obj *current)
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
		current->len_ver++;
		return (check_line(&raw_data[i], nb_args, 1) &&
			check_vertexes(&raw_data[i], tmp));
	}
	if ((tmp[0] == 'f' || tmp[0] == 'l') &&
		(tmp[1] == ' ' || tmp[1] == '\t') && current->len_ver == 0)
		return (0);
	return (dispatch_f_l_g_o(raw_data, i, tmp, nb_args));
}

/*
** the tinniest line is a texture define: "s 1"
*/

int					check_obj_raw_data(char *raw_data, t_parser_option *opt)
{
	static t_status_obj current;

	if (opt->data_len == 2 && raw_data[0] == 'g')
		return (1);
	return (opt->data_len > 2 ?
		dispatch_by_header(raw_data, opt, &current) : 0);
}
