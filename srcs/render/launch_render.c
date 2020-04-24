/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:19:54 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 17:37:36 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		terminate_reader(t_gdata *gdata)
{
	glfwDestroyWindow(gdata->win);
	// need to free gdata->obj | gdata->mtl
	glfwTerminate();
}

int render1(t_gdata *gdata)
{	
	init_shader(gdata->engine);

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * gdata->obj[0].size_vertices,
		gdata->obj[0].vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * gdata->obj[0].size_indices,
		gdata->obj[0].indices, GL_DYNAMIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
		(void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

 	// create_texture(gdata, "data/ressources/bomm.jpg", 0);
 	// create_texture(gdata, "data/ressources/mouth.jpg", 1);
	// glUseProgram(gdata->engine->program);
	// load_texture(gdata, "texture1", 0);
	// load_texture(gdata, "texture2", 1);

	glEnable(GL_DEPTH_TEST);		// https://www.khronos.org/opengl/wiki/Depth_Test
	while (!glfwWindowShouldClose(gdata->win))
	{
		// glClearColor(0.25f, 0.0f, 0.5f, 0.5f);
		dprintf(1, "\n.");
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glActiveTexture(GL_TEXTURE0);
		// glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[0]);
		// glActiveTexture(GL_TEXTURE1);
		// glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[1]);

		glBindVertexArray(VAO);
		update_matrix(gdata);

		glDrawElements(GL_TRIANGLES, gdata->obj[0].size_indices, GL_UNSIGNED_INT, 0);

		// glDrawArrays(GL_TRIANGLES, 0, gdata->obj[0].len_vertexes);
		glBindVertexArray(0);

		dprintf(1, ".");
		glfwSwapBuffers(gdata->win);
		handle_event(gdata);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}

int		 launch_render(t_gdata *gdata, t_parser *parser)
{
	if (!init_gdata(gdata, parser))
		return (0);
	glfwSetInputMode(gdata->win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	render1(gdata);
	return (1);
}
