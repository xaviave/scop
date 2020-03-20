/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/19 21:31:53 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/render.h"

int             main(int ac, char **av)
{
    t_parser    parser;
    t_prog      p;

	launch_parser(&parser, ac, av);
	launch_render(&p);
    return (p.exit_state);
}
