/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:44:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/01 18:27:55 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	init_parser(t_parser *parser, int ac, char **av)
{
	int	i;

	parser->nb_args = ac - 1;
	parser->args = av;
	if (!(parser->obj = (t_obj *)malloc(sizeof(t_obj) * parser->nb_args)))
		handle_error_parser("Error during memory allocation.");
	if (!(parser->path = (char **)malloc(sizeof(char *) * parser->nb_args)))
		handle_error_parser("Error during memory allocation.");
	i = -1;
	while (++i < parser->nb_args)
		parser->path[i] = get_path(av[i + 1]);
}

void	init_parser_mtl(t_parser *parser)
{
	int	i;
	int	len_mtl;

	i = -1;
	len_mtl = 0;
	while (++i < parser->nb_args)
	{
		if (parser->obj[i].mtllib)
		{
			parser->obj[i].mtl_id = len_mtl;
			len_mtl++;
		}
	}
	if (!(parser->mtl = (t_mtl *)malloc(sizeof(t_mtl) * len_mtl)))
		handle_error_parser("Error during memory allocation.");
}