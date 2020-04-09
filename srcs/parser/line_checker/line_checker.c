/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:03:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 19:01:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int							check_line_double(char *raw_data,
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
			if (raw_data[i] == '.')
				p++;
			else if (raw_data[i] == '-')
				m++;
			if (p > 1 || m > 1)
				return (0);
			i++;
		}
	}
	return (i == data_len);
}

int							check_line_str(char *raw_data, int data_len, int i)
{
    i = pass_whitespace(i, raw_data);
	while (raw_data[i] && raw_data[i] != '\t' && raw_data[i] != ' ')
		i++;
	return (i == data_len ? 1 : 0);
}

int							check_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len < 3)
		return (0);
	return ((opt->parsing_type == P_OBJ) ?
		check_obj_raw_data(raw_data, opt) :
		check_mtl_raw_data(raw_data, opt));
}