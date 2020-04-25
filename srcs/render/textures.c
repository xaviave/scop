/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:07:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 22:47:01 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int			get_bmp_header(t_img *img, FILE *fd)
{
	int				padding;
	int				widthnew;
	unsigned char	header[54];

	fread(header, sizeof(unsigned char), 54, fd);
	img->width = *(int*)&header[18];
	img->heigth = *(int*)&header[22];
	padding = 0;
	while ((img->width * 3 + padding) % 4 != 0)
		padding++;
	widthnew = img->width * 3 + padding;
	if (!(img->data = (unsigned char *)malloc(img->width *
		img->heigth * 3 * sizeof(unsigned char))))
		return (0);
	if (img->data == NULL)
		return (0);
	return (widthnew);
}

static void			read_data(t_img *img, FILE *fd, int widthnew,
	unsigned char *data)
{
	unsigned int	i;
	unsigned int	j;
	int				index;
	
	i = -1;
	while (++i < img->heigth)
	{
		j = 0;
		fread(data, sizeof(unsigned char), widthnew, fd);
		while (j < img->width * 3)
		{
			index = (i * img->width * 3) + (j);
			img->data[index + 0] = data[j + 2];
			img->data[index + 1] = data[j + 1];
			img->data[index + 2] = data[j + 0];
			j += 3;
		}
	}
	free(data);
}

static int			read_bmp(t_img *img, char *name)
{
	FILE			*fd;
	int				widthnew;
	unsigned char	*data;
	
	fd = fopen(name, "rb");
	if (fd == NULL)
		return (0);
	widthnew = get_bmp_header(img, fd);
	if (!widthnew ||
		!(data = (unsigned char *)malloc(widthnew * sizeof(unsigned char))))
		return (0);
	read_data(img, fd, widthnew, data);
	fclose(fd);
	return (1);
}

void				create_texture(t_gdata *gdata, char *name, unsigned int t)
{
	t_img			img;

	read_bmp(&img, name);
	ft_printf("%d %d %s\n", img.width, img.heigth, img.data);
	glGenTextures(1, &(gdata->engine->texture_id[t]));
	glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[t]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width,
		img.heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void				load_texture(t_gdata *gdata, char *name, unsigned int t)
{
	unsigned int	id;

	id = glGetUniformLocation(gdata->engine->program, name);
	glUniform1i(id, gdata->engine->texture_id[t]);
}
