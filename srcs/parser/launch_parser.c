/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:44 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:26:58 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** check_args: check every args of the main
** no_args -> return usage
** file w/o .obj extension -> return error
*/

static void	check_args(int ac, char **av)
{
	int		i;
	char	*tmp;

	if (ac < 2)
		handle_error_parser("No args provided, need at least one object file.", NULL);
    i = 0;
	while (++i < ac)
	{
	    if (ft_strlen(av[i]) < 5)
            handle_error_parser("Invalid file name.", NULL);
		else if (!(tmp = ft_strsub(av[i], ft_strlen(av[i]) - 4, ft_strlen(av[i]))))
            handle_error_parser("Error during memory allocation.", NULL);
		else if (ft_strcmp(".obj", tmp))
		{
		    ft_strdel(&tmp);
            handle_error_parser("Invalid file name.", NULL);
        }
		ft_strdel(&tmp);
	}
}

int 		launch_parser(t_parser *parser, int ac, char **av)
{
	check_args(ac, av);
	init_parser(parser, ac, av);
	reader_obj(parser);
	init_parser_mtl(parser);
	reader_mtl(parser);
	return (0);
}
