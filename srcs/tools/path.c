/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:56:06 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:22 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

char		*get_path(char *str)
{
	int		pos_delim;
	char	*path;

	pos_delim = ft_strlen(str) - last_char(str, '/');
	if (!pos_delim)
		return (ft_strdup("./"));
	if (!(path = ft_strndup(str, pos_delim)))
		return (NULL);
	path[pos_delim] = '\0';
	return (path);
}

char		*create_path(char *directory, char *file)
{
	char	*tmp;

	if (directory[ft_strlen(directory) - 1] != '/')
	{
		tmp = directory;
		if (!(directory = ft_strjoin(directory, "/\0")))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
	}
	return (ft_strjoin(directory, file));
}
