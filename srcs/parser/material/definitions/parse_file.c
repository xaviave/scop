/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:04:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/13 13:55:38 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int					parser_xpm(t_file *file)
{
	// here load xpm not done for now
	if (file)
		return (1);
	return (1);
}

int 						parse_file(t_file *file, char *raw_data, char *path)
{
	int						i;

	if (!(file->name = ft_strtrim(raw_data)))
	    return (0);
	if (!(file->path = create_path(path, file->name)))
		return (0);
	i = ft_strlen(file->name) - 3;
	if (ft_strcmp(&file->name[i], "xpm"))
    {
        ft_printf("Can't parse file: %s\n", &raw_data[i]);
        return (0);
    }
	ft_memset(&file->img, 0, sizeof(t_img));
	return (parser_xpm(file));
}