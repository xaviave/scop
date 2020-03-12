/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:44 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 11:35:44 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static void	init_parser(t_parser *parser)
{
	parser->name = malloc(7 * sizeof(char));
	parser->name = "xavier";
}

void		launch_parser(t_parser *parser)
{
	init_parser(parser);
	ft_printf("%s\n", parser->name);
}
