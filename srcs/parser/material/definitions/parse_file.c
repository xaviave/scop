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

static int			reader_file(char *name, char **data)
{
	int				fd;
	int				ret;
	int				file_size;
	char			*tmp;
	char			line[IMG_BUFFER];

	if (!(fd = open(name, O_RDONLY)))
	    return (0);
	file_size = 0;
	while ((ret = read(fd, &line, IMG_BUFFER)) > 0)
	{
		tmp = *data;
		if (!(*data = ft_memalloc(file_size + ret)))
        {
		    ft_strdel(&tmp);
		    close(fd);
		    return (0);
        }
		if (tmp)
			ft_memcpy(*data, tmp, file_size);
		ft_memcpy(*data + file_size, line, ret);
		file_size += ret;
		ft_strdel(&tmp);
	}
    return (close(fd) == -1 ? 0 : 1);
}

unsigned int		read_header(char *filename, t_img *img)
{
	int				bpp;
	FILE			*file;

	if ((file = fopen(filename, "r")) == NULL)
		return (0);
	fseek(file, 18, SEEK_SET);
	fread(&img->width, 4, 1, file);
	fread(&img->heigth, 4, 1, file);
	fseek(file, 2, SEEK_CUR);
	fread(&bpp, 2, 1, file);
	fclose(file);
	img->width = abs(img->width);
	img->heigth = abs(img->heigth);
	return (img->width * (bpp / 8));
}

static int			read_bmp(t_img *img, char *name, unsigned int sl)
{
	int				h;
	unsigned int	j;
	unsigned int	i;
	char			*tmp;

	h = 0;
	i = sl * img->heigth;
	tmp = NULL;
	if (!(reader_file(name, &tmp)))
        return (0);
    while (i > 0)
	{
        i -= sl;
		j = 0;
		while (j < sl)
		{
			img->data[h + j] = (unsigned char)tmp[i + j + 2];
			img->data[h + j + 1] = (unsigned char)tmp[i + j + 1];
			img->data[h + j + 2] = (unsigned char)tmp[i + j];
			j += 3;
		}
		h += sl;
	}
    ft_strdel(&tmp);
	return (1);
}

int					parse_bmp(t_img *img, char *name)
{
	unsigned int	sl;

	img->data = NULL;
	if (!(sl = read_header(name, img)))
        return (0);
	if (!(img->data = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
	        (sl * img->heigth) * 2)))
	    return (0);
	if (!(read_bmp(img, name, sl)))
        return (0);
	return (1);
}

int 				parse_file(t_file *file, char *raw_data, char *path)
{
	if (file)
		ft_printf("Can't parse file: %s%s\n", path, raw_data);
	return (0);
}