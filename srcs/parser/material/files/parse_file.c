/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:04:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/10 22:48:36 by xamartin         ###   ########lyon.fr   */
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

static int					reader_file(t_file *file, int *file_size)
{
	int		fd;
	char	line[50];
	int		ret;
	char	*tmp;

	fd = open(file->path, O_RDONLY);
	*file_size = 0;
	file->data = NULL;
	while ((ret = read(fd, &line, 50)) > 0)
	{
		tmp = file->data;
		file->data = ft_memalloc((*file_size) + ret);
		if (tmp)
			ft_memcpy(file->data, tmp, (*file_size));
		ft_memcpy(file->data + (*file_size), line, ret);
		(*file_size) += ret;
		if (tmp)
			free(tmp);
	}
	if (file->data)
		return (1);
	return (0);
}

int 						parse_file(t_file *file, char *raw_data, char *path)
{
	int						i;
	int						file_size;
	int						(*f[10])(t_file *);

	if (!(file->name = ft_strtrim(raw_data)))
	    return (0);
	if (!(file->path = create_path(path, file->name)))
		return (0);
	i = ft_strlen(file->name) - 3;
	if ((file->type = define_file_type(&file->name[i])) == -1)
    {
        ft_printf("Can't parse RFL file or this file extention: %s\n", &raw_data[i]);
        return (0);
    }
	ft_printf("really long to read a png (8s) so need parallization with thread or something\n");
	file->data = NULL;
	if (!(reader_file(file, &file_size)))
		return (0);
	file->nb_octet = file_size;
	init_file_ptr(f);
	return (f[file->type](file));
}