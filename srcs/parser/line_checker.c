/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:03:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/25 20:23:22 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static int					check_line_double(char *raw_data, int i)
{
	int						p;
	int						m;

	while (raw_data[i])
	{
		p = 0;
		m = 0;
		i = pass_whitespace(i, raw_data);
		if (raw_data[i] == '.' || raw_data[i] == '/' ||
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
		else if (raw_data[i] != '\t' || raw_data[i] != ' ')
			return (0);
	}
	return (((size_t)i == ft_strlen(raw_data)) ? 1 : 0);
}

static int					check_line_str(char *raw_data, int i)
{
    i = pass_whitespace(i, raw_data);
	while (raw_data[i] && raw_data[i] != '\t' && raw_data[i] != ' ')
		i++;
	return (((size_t)i == ft_strlen(raw_data)) ? 1 : 0);
}

static int					dispatch_by_header(char *raw_data)
{
	char					tmp[3];

	ft_bzero(tmp, 3);
	ft_strncpy(tmp, raw_data, 2);
	if (ft_strlen(raw_data) > 8 && (ft_strstr(raw_data, "usemtl") ||
		ft_strstr(raw_data, "mtllib")))
		return (1);
	else if (ft_strstr(tmp, "vt") || ft_strstr(tmp, "vn") ||
		ft_strstr(tmp, "vp"))
		return check_line_double(raw_data, 2);
	else if (ft_strstr(tmp, "g") || ft_strstr(tmp, "o"))
		return check_line_str(raw_data, 1);
	else if (ft_strstr(tmp, "v") || ft_strstr(tmp, "l") ||
		ft_strstr(tmp, "f"))
		return check_line_double(raw_data, 1);
	else if (ft_strstr(tmp, "#") || ft_strstr(tmp, "s"))
		return (1);
	return (0);
}

/*
** the tinniest line is a texture define: "s 1"
*/

static int					check_obj_raw_data(char *raw_data)
{
	if (ft_strlen(raw_data) == 2 && raw_data[0] == 'g')
		return (1);
    return (ft_strlen(raw_data) > 2 ? dispatch_by_header(raw_data) : 0);
}

static int					check_mtl_raw_data(char *raw_data)
{
	if (ft_strlen(raw_data))
		return (0);
	return (1);
}

int							check_raw_data(char *raw_data, short parsing_type)
{
	if (ft_strlen(raw_data) < 3)
		return (0);
	return ((parsing_type == P_OBJ) ?
		check_obj_raw_data(raw_data) : check_mtl_raw_data(raw_data));
}