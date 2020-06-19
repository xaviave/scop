/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:54:01 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 17:54:05 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int	check_line_str(char *raw_data, int data_len, int i)
{
	i = pass_whitespace(i, raw_data);
	while (raw_data[i] && raw_data[i] != '\t' && raw_data[i] != ' ')
		i++;
	return (i == data_len ? 1 : 0);
}

int	check_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len < 3)
		return (0);
	return ((opt->parsing_type == P_OBJ) ?
		check_obj_raw_data(raw_data, opt) :
		check_mtl_raw_data(raw_data, opt));
}
