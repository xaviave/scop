/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:36:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "render.h"

int             main(int ac, char **av)
{
    t_parser    parser;
    t_prog      p;

	launch_parser(&parser, ac, av);
	(void)p;
	// launch_render(&p, &parser);
    return (1);
}
