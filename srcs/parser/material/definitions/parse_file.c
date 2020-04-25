/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:04:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 21:53:22 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int 				parse_file(t_file *file, char *raw_data, char *path)
{
	int				i;

	if (!(file->name = ft_strtrim(raw_data)))
	    return (0);
	if (!(file->path = create_path(path, file->name)))
		return (0);
	i = ft_strlen(file->name) - 3;
	if (ft_strcmp(&file->name[i], "bmp"))
    {
        ft_printf("Can't parse file: %s\n", &raw_data[i]);
        return (0);
    }
	return (1);
}