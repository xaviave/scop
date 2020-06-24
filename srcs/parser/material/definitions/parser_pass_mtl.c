/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pass_mtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:00:11 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:12 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int					parser_pass_mtl(t_mtl *mtl, char *raw_data, int group_id)
{
	if (raw_data[0] != '#' && ft_strstr(raw_data, "newmtl"))
	{
		if (!(mtl->groups[group_id] = ft_strtrim(&raw_data[6])))
			return (0);
	}
	return (1);
}
