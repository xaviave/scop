/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:15:33 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:29:26 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

int	init_buffer(t_gdata *gdata)
{
	glGenVertexArrays(1, &(gdata->buffer->vao));
	glGenBuffers(1, &(gdata->buffer->vbo_vertices));
	glGenBuffers(1, &(gdata->buffer->vbo_indices));
	glBindVertexArray(gdata->buffer->vao);
	glBindBuffer(GL_ARRAY_BUFFER, gdata->buffer->vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * gdata->obj[0].size_vertices,
		gdata->obj[0].vertices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gdata->buffer->vbo_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * gdata->obj[0].size_indices,
		gdata->obj[0].indices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
		(void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	return (1);
}
