/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pass_mtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:00:11 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:01:20 by ltoussai         ###   ########lyon.fr   */
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
	else
		printf("This line is ignored | mtl id = %d | data = %s\n",
			mtl->id, raw_data);
	return (1);
}
