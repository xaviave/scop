/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:18:48 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 20:51:48 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

// static int					check_color(char *raw_data)
// {
// 	int						tmp;

// 	tmp = ft_atoi(raw_data);
// 	if (tmp == 0 || tmp == 1)
// 		return (1);
// 	return (0);
// }

int					check_mtl_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len && raw_data)
		return (1);
	return (0);
}