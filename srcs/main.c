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

static int      init_t_prog(t_prog *p)
{
    p->win = NULL;
    return (p->exit_state);
}

int             main(int ac, char **av)
{
    t_parser    parser;
    t_prog      p;

	p.exit_state = launch_parser(&parser, ac, av);
    init_t_prog(&p); // try to launch everythings in functions not in the main please
    manage_sdl(&p);
    return (p.exit_state);
}
