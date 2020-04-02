/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:25:34 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/29 16:03:09 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void    init_parser_option(t_parser_option *opt, char *file,
        int index, short parsing_type)
{
	ft_memset(opt, 0, sizeof(t_parser_option));
	opt->parsing_type = parsing_type;
	opt->file = file;
	opt->index = index;
}
