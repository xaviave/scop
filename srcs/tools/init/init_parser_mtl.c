/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_mtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 12:12:04 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/20 12:12:06 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"
#include "../../../includes/cleaner.h"

void		init_parser_mtl(t_parser *parser)
{
	int		i;
	int		len_mtl;

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
