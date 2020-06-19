/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:36:35 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:36:47 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

int					create_texture(t_gdata *gdata, char *name)
{
	t_img			img;

	if (!(parse_bmp(&img, name)))
	{
		printf("Error during parsing texture.\n");
		ft_memdel((void **)&img.data);
		return (0);
	}
	glGenTextures(1, &gdata->engine->texture_id);
	glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width,
		img.heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	ft_memdel((void **)&img.data);
	return (1);
}
