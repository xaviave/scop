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

static int			get_bmp_header(t_file *file, FILE *fd)
{
	int				padding;
	int				widthnew;
	unsigned char	header[54];

	fread(header, sizeof(unsigned char), 54, fd);
	file->img.width = *(int*)&header[18];
	file->img.heigth = *(int*)&header[22];
	padding = 0;
	ft_printf("ue\n");
	while ((file->img.width * 3 + padding) % 4 != 0)
		padding++;
	widthnew = file->img.width * 3 + padding;
	ft_printf("ue\n");
	if (!(file->img.data = (unsigned char *)malloc(file->img.width *
		file->img.heigth * 3 * sizeof(unsigned char))))
		return (0);
	if (file->img.data == NULL)
		return (0);
	return (widthnew);
}

static void			read_data(t_file *file, FILE *fd, int widthnew,
	unsigned char *data)
{
	unsigned int	i;
	unsigned int	j;
	int				index;
	
	i = -1;
	while (++i < file->img.heigth)
	{
		j = 0;
		fread(data, sizeof(unsigned char), widthnew, fd);
		while (j < file->img.width * 3)
		{
			index = (i * file->img.width * 3) + (j);
			file->img.data[index + 0] = data[j + 2];
			file->img.data[index + 1] = data[j + 1];
			file->img.data[index + 2] = data[j + 0];
			j += 3;
		}
	}
	free(data);
}

static int			read_bmp(t_file *file)
{
	FILE			*fd;
	int				widthnew;
	unsigned char	*data;
	
	fd = fopen(file->path, "rb");
	if (fd == NULL)
		return (0);
	widthnew = get_bmp_header(file, fd);
	ft_printf("%d\n", widthnew);
	if (!widthnew ||
		!(data = (unsigned char *)malloc(widthnew * sizeof(unsigned char))))
		return (0);
	read_data(file, fd, widthnew, data);
	fclose(fd);
	return (1);
}

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
	return (read_bmp(file));
}