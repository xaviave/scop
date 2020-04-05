/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:25:34 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:30:38 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void					init_parser_option(t_parser_option *opt, char *file,
	int index, short parsing_type)
{
	ft_memset(opt, 0, sizeof(t_parser_option));
	opt->parsing_type = parsing_type;
	opt->file = file;
	opt->index = index;
}
