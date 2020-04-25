/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:19:54 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 22:01:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		terminate_reader(t_gdata *gdata)
{
	glfwDestroyWindow(gdata->win);
	glDeleteVertexArrays(1, &gdata->buffer->vao);
	glDeleteBuffers(1, &gdata->buffer->vbo_indices);
	glDeleteBuffers(1, &gdata->buffer->vbo_vertices);
	// need to free gdata->obj | gdata->mtl | in each obj vertices | indices
	glfwTerminate();
}

static void	render(t_gdata *gdata)
{
	if (gdata->obj[gdata->actual_obj].mtllib)
	{
 		create_texture(gdata, 0);
		glUseProgram(gdata->engine->program);
		load_texture(gdata, "my", 0);
	}
	while (!glfwWindowShouldClose(gdata->win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (gdata->obj[gdata->actual_obj].mtllib)
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[0]);
		}
		update_matrix(gdata);
		glUniform1i(gdata->buffer->grey_loc, gdata->engine->grey);
		glUniform1i(gdata->buffer->texture_loc, gdata->engine->texture);
		glUniform1i(gdata->buffer->random_loc, gdata->engine->random);
		glBindVertexArray(gdata->buffer->vao);
		glDrawElements(GL_TRIANGLES,
			gdata->obj[gdata->actual_obj].size_indices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(gdata->win);
		handle_event(gdata);
	}
	terminate_reader(gdata);
}

int		 	launch_render(t_gdata *gdata, t_parser *parser)
{
	if (!init_gdata(gdata, parser))
		return (0);
	render(gdata);
	return (1);
}
