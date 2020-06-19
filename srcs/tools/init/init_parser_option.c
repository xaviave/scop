/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:00:09 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 20:00:13 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"

void	init_parser_option(t_parser_option *opt, char *file,
		int index, short parsing_type)
{
	ft_memset(opt, 0, sizeof(t_parser_option));
	opt->parsing_type = parsing_type;
	opt->file = file;
	opt->index = index;
}
