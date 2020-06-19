/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:11:07 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 21:03:27 by ltoussai         ###   ########lyon.fr   */
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
