/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 21:33:44 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

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
    // manage_sdl(&p);
    return (p.exit_state);
}
