/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:07:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 22:00:41 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

/*
** https://learnopengl.com/Getting-started/Textures
** no more put pixel by pixel, you have to fill a char* gdata->text
** then it will be display a once in glTexImage2D
*/

void				create_texture(t_gdata *gdata, unsigned int t)
{
	glGenTextures(1, &(gdata->engine->texture_id[t]));
	glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[t]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		gdata->mtl[gdata->actual_obj].ac->file.img.width,
		gdata->mtl[gdata->actual_obj].ac->file.img.heigth, 0, GL_RGB,
		GL_UNSIGNED_BYTE, gdata->mtl[gdata->actual_obj].ac->file.img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void				load_texture(t_gdata *gdata, char *name, unsigned int t)
{
	unsigned int	id;

	id = glGetUniformLocation(gdata->engine->program, name);
	glUniform1i(id, gdata->engine->texture_id[t]);
}
