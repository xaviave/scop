/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:44:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:30:33 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"
#include "../../../includes/cleaner.h"

void	init_parser(t_parser *parser, int ac, char **av)
{
	int	i;

	parser->nb_args = ac - 1;
	parser->args = av;
	parser->addr = NULL;
	if (!(parser->obj = addr_add((t_obj *)ft_memalloc(sizeof(
	        t_obj) * parser->nb_args), M_OBJ_, &parser->addr)))
		handle_error_parser("Error during memory allocation.", &parser->addr);
	if (!(parser->path = addr_add((char **)malloc(sizeof(
	        char *) * ac), M_CHAR__, &parser->addr)))
		handle_error_parser("Error during memory allocation.", &parser->addr);
	parser->path[ac - 1] = NULL;
	i = -1;
	while (++i < parser->nb_args)
        if (!(parser->path[i] = get_path(av[i + 1])))
            handle_error_parser("Error during memory allocation.", &parser->addr);
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
		handle_error_parser("Error during memory allocation.", NULL);
}
