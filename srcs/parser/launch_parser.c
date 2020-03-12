/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:44 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 13:25:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	init_parser(t_parser *parser, int ac, char **av)
{
	parser->nb_args = ac - 1;
	parser->args = av;
	ft_printf("parser->args = %p\nav = %p", parser->args, av);
}

static void	check_args(int ac, char **av)
{
	if (ac < 2)
		handle_error("No args provided, need at least one object file");
		
}

void		launch_parser(t_parser *parser, int ac, char **av)
{
	check_args(ac, av);
	init_parser(parser, ac, av);
	reader(parser);
}
