/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:29:06 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:29:21 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void	put_uniform(t_gdata *gdata)
{
	gdata->buffer->grey_loc =
		glGetUniformLocation(gdata->engine->program, "grey");
	gdata->buffer->sample_loc =
		glGetUniformLocation(gdata->engine->program, "sample_text");
	gdata->buffer->texture_loc =
		glGetUniformLocation(gdata->engine->program, "texture");
	gdata->buffer->random_loc =
		glGetUniformLocation(gdata->engine->program, "random");
	glGetUniformLocation(gdata->engine->program, "texture2d");
}

int			init_buffer(t_gdata *gdata)
{
	glGenVertexArrays(1, &(gdata->buffer->vao));
	glGenBuffers(1, &(gdata->buffer->vbo_vertices));
	glGenBuffers(1, &(gdata->buffer->vbo_indices));
	glBindVertexArray(gdata->buffer->vao);
	glBindBuffer(GL_ARRAY_BUFFER, gdata->buffer->vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * gdata->obj[0].size_vertices,
		gdata->obj[0].vertices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gdata->buffer->vbo_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(int) * gdata->obj[0].size_indices,
			gdata->obj[0].indices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
		(void*)0);
	glEnableVertexAttribArray(1);
	put_uniform(gdata);
	return (1);
}
