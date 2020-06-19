/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:35:40 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:36:00 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void	terminate_render(t_gdata *gdata)
{
	glfwMakeContextCurrent(NULL);
	glfwDefaultWindowHints();
	glDeleteVertexArrays(1, &gdata->buffer->vao);
	glDeleteBuffers(1, &gdata->buffer->vbo_indices);
	glDeleteBuffers(1, &gdata->buffer->vbo_vertices);
	glDeleteProgram(gdata->engine->program);
}

static int	render(t_gdata *gdata)
{
	glEnable(GL_PROGRAM_POINT_SIZE);
	if (!(create_texture(gdata, "data/ressources/image.bmp")))
		return (0);
	while (!glfwWindowShouldClose(gdata->win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id);
		if (!(update_matrix(gdata)))
			return (0);
		glUniform1i(gdata->buffer->grey_loc, gdata->engine->grey);
		glUniform1i(gdata->buffer->sample_loc, gdata->engine->texture);
		glUniform1i(gdata->buffer->texture_loc, gdata->engine->texture);
		glUniform1i(gdata->buffer->random_loc, gdata->engine->random);
		glBindVertexArray(gdata->buffer->vao);
		glDrawElements(GL_TRIANGLES,
			gdata->obj[gdata->actual_obj].size_indices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(gdata->win);
		handle_event(gdata);
	}
	terminate_render(gdata);
	return (1);
}

int			launch_render(t_gdata *gdata, t_parser *parser)
{
	gdata->addr = parser->addr;
	if (!init_gdata(gdata, parser))
		handle_error_render("Error during init render.", &gdata->addr);
	if (!(render(gdata)))
		handle_error_render("Error during render.", &gdata->addr);
	delete_addr_render(&gdata->addr);
	return (1);
}
