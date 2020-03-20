/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:44 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 17:12:35 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_parser(t_parser *parser, int ac, char **av)
{
	parser->nb_args = ac;
	parser->args = av;
	ft_printf("ac = %d", ac);
	if ((parser->obj = (t_obj *)malloc(sizeof(t_obj) * ac - 1)))
		handle_error_parser("Error during memory allocation");
}

/*
** check_args: check every args of the main
** no_args -> return usage
** file w/o .obj extention -> return error
*/

static void	check_args(int ac, char **av)
{
	int		i;
	int		err;
	char	*tmp;

	i = 0;
	if (ac < 2)
		handle_error_parser("No args provided, need at least one object file");
	while (++i < ac)
	{
		tmp = ft_strsub(av[i], ft_strlen(av[i]) - 4, ft_strlen(av[i]));
		err = ft_strlen(av[i]) < 5 || ft_strcmp(".obj", tmp);
		free_str(tmp);
		if (err)
			handle_error_parser("Invalid file name");
	}
}

int 		launch_parser(t_parser *parser, int ac, char **av)
{
	check_args(ac, av);
	init_parser(parser, ac, av);
	reader(parser);
	return (0);
}
