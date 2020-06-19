/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:29:32 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 17:35:31 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
		handle_error_parser("No args provided, need at least one object file.",
			NULL);
	i = 0;
	while (++i < ac)
	{
		if (ft_strlen(av[i]) < 5)
			handle_error_parser("Invalid file name.", NULL);
		else if (!(tmp = ft_strsub(av[i], ft_strlen(av[i]) - 4,
				ft_strlen(av[i]))))
			handle_error_parser("Error during memory allocation.", NULL);
		else if (ft_strcmp(".obj", tmp))
		{
			ft_strdel(&tmp);
			handle_error_parser("Invalid file name.", NULL);
		}
		ft_strdel(&tmp);
	}
}

int			launch_parser(t_parser *parser, int ac, char **av)
{
	check_args(ac, av);
	init_parser(parser, ac, av);
	reader_obj(parser);
	init_parser_mtl(parser);
	reader_mtl(parser);
	clear_parser_memory(&parser->addr);
	return (0);
}
