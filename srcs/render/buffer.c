/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:15:33 by xamartin          #+#    #+#             */
/*   Updated: 2020/05/20 20:26:49 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

static void put_uniform(t_gdata *gdata)
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

static void	init_color(t_gdata *gdata)
{
	int					i;
	float				tmp[3];


	i = -1;
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	gdata->size_color = gdata->obj[0].size_vertices;	
	if (!(gdata->color = (float *)malloc(sizeof(float) * gdata->size_color)))
		return ;
	while (++i < gdata->size_color)
	{
		tmp[0] += gdata->obj[0].vertices[i];
		tmp[1] += gdata->obj[0].vertices[i + 1];
		tmp[2] += gdata->obj[0].vertices[i + 2];
		if (i % 3 == 0)
		{
			gdata->color[i] = (tmp[0] / 3) / 255;
			gdata->color[i + 1] = (tmp[1] / 3) / 255;
			gdata->color[i + 2] = (tmp[2] / 3) / 255;
			tmp[0] = 0;
			tmp[1] = 0;
			tmp[2] = 0;
			gdata->color[i] = 0.2;
			gdata->color[i + 1] = 0.2;
			gdata->color[i + 2] = 0.2;
		}
		i += 3;
	}
}

int			init_buffer(t_gdata *gdata)
{
	init_color(gdata);
	glGenVertexArrays(1, &(gdata->buffer->vao));
	glGenBuffers(1, &(gdata->buffer->vbo_vertices));
	glGenBuffers(1, &(gdata->buffer->vbo_indices));
	glBindVertexArray(gdata->buffer->vao);
	glBindBuffer(GL_ARRAY_BUFFER, gdata->buffer->vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * gdata->obj[0].size_vertices,
		gdata->obj[0].vertices, GL_DYNAMIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * gdata->size_color,
		gdata->color, GL_DYNAMIC_DRAW);
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
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);
	put_uniform(gdata);
	return (1);
}
