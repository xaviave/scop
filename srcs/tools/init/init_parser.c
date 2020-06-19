/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:59:41 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 20:37:52 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"
#include "../../../includes/cleaner.h"

void		init_parser(t_parser *parser, int ac, char **av)
{
	int		i;

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
			handle_error_parser("Error during memory allocation.",
				&parser->addr);
}


void		init_parser_mtl(t_parser *parser)
{
	int		i;
	int		len_mtl;

	i = -1;
	len_mtl = 0;
	while (++i < parser->nb_args)
		if (parser->obj[i].mtllib)
		{
			parser->obj[i].mtl_id = len_mtl;
			len_mtl++;
		}
	if (len_mtl)
	{
		if (!(parser->mtl = addr_add((t_mtl *)ft_memalloc(sizeof(
				t_mtl) * len_mtl), M_MTL_, &parser->addr)))
			handle_error_parser("Error during memory allocation.",
			&parser->addr);
		i = 0;
		while (i < len_mtl)
			parser->mtl[i++].nb_args = len_mtl;
	}
}
