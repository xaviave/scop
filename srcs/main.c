/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/05/03 12:34:23 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "render.h"

int             main(int ac, char **av)
{
    t_parser    parser;
    t_gdata      g;

	launch_parser(&parser, ac, av);
//	handle_error_parser("test exit after parser.", &parser.addr);
    clear_parser_memory(&parser.addr);
	launch_render(&g, &parser);
	handle_error_render("test exit after render.", &g.addr);
    return (0);
}
