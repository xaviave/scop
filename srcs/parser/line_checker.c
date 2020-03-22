/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:03:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 11:44:40 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

/*
** all allowed char are : "vtnpfl0123456789./-"
*/

static int					check_line_double(char *raw_data, int i)
{
	int						p;
	int						m;

	while (raw_data[i])
	{
		p = 0;
		m = 0;
		i = pass_whitespace(i, raw_data);
		while (raw_data[i] == '.' || raw_data[i] == '/' ||
			raw_data[i] == '-' || (raw_data[i] >= '0' && raw_data[i] <= '9'))
		{
			if (raw_data[i] == '.')
				p++;
			else if (raw_data[i] == '-')
				m++;
			if (p > 1 || m > 1)
				return (0);
			i++;
		}
	}
	return (((size_t)i == ft_strlen(raw_data)) ? 1 : 0);
}

static int					check_line_str(char *raw_data, int i)
{
    i = pass_whitespace(i, str);
	while (raw_data[i] && raw_data[i] != '\t' && raw_data[i] != ' ' &&
		raw_data[i] != '\n' && raw_data[i] != '\r')
		i++;
	return (((size_t)i == ft_strlen(raw_data)) ? 1 : 0);
}

static int					dispatch_by_header(char *raw_data)
{
	if (ft_strstr(raw_data, "vt") || ft_strstr(raw_data, "vn") ||
		ft_strstr(raw_data, "vp"))
		return check_line_double(raw_data, 2);
	else if (ft_strstr(raw_data, "g") || ft_strstr(raw_data, "o"))
		return check_line_str(raw_data, 1);
	else if (ft_strlen(raw_data) > 7 && (ft_strstr(raw_data, "usemtl") ||
		ft_strstr(raw_data, "mtllib")))
		return check_line_str(raw_data, 6);
	else if (ft_strstr(raw_data, "v") || ft_strstr(raw_data, "l") ||
		ft_strstr(raw_data, "f"))
		return check_line_double(raw_data, 1);
	return (0);
}

/*
** the tinniest line is a texture define: "vt 1"
*/

int							check_raw_data(char *raw_data)
{
    return (ft_strlen(raw_data) < 4 ? 0 : dispatch_by_header(raw_data));
}