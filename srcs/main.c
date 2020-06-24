/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:11:07 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:05 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "render.h"

int				main(int ac, char **av)
{
	t_parser	parser;
	t_gdata		g;

	launch_parser(&parser, ac, av);
	launch_render(&g, &parser);
	return (0);
}
