/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/31 22:38:54 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int             main(int ac, char **av)
{
    t_parser    parser;
    t_prog      p;

//    (void)av;
//    (void)ac;
//    (void)parser; // uncomment when need to dodge parsing.
	launch_parser(&parser, ac, av);
//	launch_render(&p);
    return (p.exit_state);
}
