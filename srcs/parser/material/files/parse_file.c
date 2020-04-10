/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:04:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 12:32:32 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

static int					define_file_type(char *type)
{
	ft_printf("type = %s\n", type);
	if (!ft_strcmp(type, "rfl"))
	    return (-1);
	else if (!ft_strcmp(type, "bmp"))
		return (F_BMP);
	else if (!ft_strcmp(type, "png"))
		return (F_PNG);
	else if (!ft_strcmp(type, "jpg"))
		return (F_JPG);
	else if (!ft_strcmp(type, "jpeg"))
		return (F_JPEG);
	else if (!ft_strcmp(type, "cxc"))
		return (F_CXC);
	else if (!ft_strcmp(type, "cxs"))
		return (F_CXS);
	else if (!ft_strcmp(type, "cxb"))
		return (F_CXB);
	else if (!ft_strcmp(type, "mps"))
		return (F_MPS);
	else if (!ft_strcmp(type, "mpb"))
		return (F_MPB);
	else if (!ft_strcmp(type, "mpc"))
		return (F_MPC);
	return (-1);
}

static int					reader_file(t_file *file)
{
	ft_printf("need a char * with the image data, dont use gnl\n");
	if (file)
		return (1);
	return (1);
}

int 						parse_file(t_file *file, char *raw_data, char *path)
{
	int						i;
	char					*tmp;
	int						(*f[10])(t_file *);

	if (!(tmp = ft_strtrim(raw_data)))
	    return (0);
	if (!(file->name = create_path(path, tmp)))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	i = ft_strlen(file->name) - 3;
	if ((file->type = define_file_type(&file->name[i])) == -1)
    {
        ft_printf("Can't parse RFL file or this file extention: %s\n", &raw_data[i]);
        return (0);
    }
	if (!(reader_file(file)))
		return (0);
	init_file_ptr(f);
	return (f[file->type](file));
}