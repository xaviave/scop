/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser_to_mtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:07:53 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 18:14:37 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int			check_mtl(t_mtl *mtl)
{
	int				i;
	int				j;

	i = -1;
	if (mtl)
	{
		while (++i < mtl->nb_groups)
		{
			j = i;
			while (++j < mtl->nb_groups)
				if (!ft_strcmp(mtl->groups[i], mtl->groups[j]))
				{
					printf("Duplicate newmtl: %s\n", mtl->groups[j]);
					return (0);
				}
		}
		return (1);
	}
	return (1);
}

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list,
		t_addr **addr)
{
	int				group_id;
	t_list_parser	*tmp;
	int				(*f[13])(t_mtl *, char *, int);

	group_id = -1;
	tmp = list;
	init_parser_mtl_ptr(f);
	while (tmp)
	{
		if (tmp->id == ID_ERR_MTL && tmp->data[0] == 'n')
			group_id++;
		if (!(f[tmp->id](mtl, tmp->data, group_id)))
			handle_error_parser("Error during memory allocation.", addr);
		tmp = tmp->next;
	}
	return (check_mtl(mtl));
}
