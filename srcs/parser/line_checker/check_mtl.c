/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:18:48 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 18:19:35 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int					check_mtl_raw_data(char *raw_data, t_parser_option *opt)
{
	if (opt->data_len && raw_data)
		return (1);
	return (0);
}