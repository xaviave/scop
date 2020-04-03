/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:03:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/03 20:51:28 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static int					check_line_double(char *raw_data,
        int data_len, int i, short max_elem)
{
	int						p;
	int						m;
	int						tmp;

	tmp = -1;
	while (raw_data[i] && ++tmp < max_elem)
	{
		p = 0;
		m = 0;
		i = pass_whitespace(i, raw_data);
		while (raw_data[i] == '.' || raw_data[i] == '/' ||
			raw_data[i] == '-' || (raw_data[i] >= '0' && raw_data[i] <= '9'))
		{
		    // Ces lignes n'ont pas de sens, il faudra en discuter.
			if (raw_data[i] == '.')
				p++;
			else if (raw_data[i] == '-')
				m++;
			if (p > 1 || m > 1)
				return (0);
			i++;
		}
	}
	return ((i == data_len) ? 1 : 0);
}

static int					check_line_str(char *raw_data, int data_len, int i)
{
    i = pass_whitespace(i, raw_data);
	while (raw_data[i] && raw_data[i] != '\t' && raw_data[i] != ' ')
		i++;
	return (i == data_len ? 1 : 0);
}

static int					dispatch_by_header(char *raw_data, t_parser_option *opt)
{
	char					tmp[3];

	ft_bzero(tmp, 3);
	ft_strncpy(tmp, raw_data, 2);
	if (opt->data_len > 8 && (ft_strstr(raw_data, "usemtl") ||
		ft_strstr(raw_data, "mtllib")))
		return (1);
	else if (ft_strstr(tmp, "vt") || ft_strstr(tmp, "vn") ||
		ft_strstr(tmp, "vp"))
		return check_line_double(raw_data, opt->data_len, 2, 3);
	else if (ft_strstr(tmp, "g") || ft_strstr(tmp, "o"))
		return check_line_str(raw_data, opt->data_len, 1);
	else if (ft_strstr(tmp, "v") || ft_strstr(tmp, "l") ||
		ft_strstr(tmp, "f"))
		return check_line_double(raw_data, opt->data_len, 1,
			(ft_strstr(tmp, "v")) ? 3 : 4);
	else if (ft_strstr(tmp, "#") || ft_strstr(tmp, "s"))
		return (1);
	return (0);
}

/*
** the tinniest line is a texture define: "s 1"
*/

static int					check_obj_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len == 2 && raw_data[0] == 'g')
		return (1);
    return (opt->data_len > 2 ? dispatch_by_header(raw_data, opt) : 0);
}

static int					check_mtl_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len)
		return (1);
	return (0);
}

int							check_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len < 3)
		return (0);
	return ((opt->parsing_type == P_OBJ) ?
		check_obj_raw_data(raw_data, opt) :
		check_mtl_raw_data(raw_data, opt));
}