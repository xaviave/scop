/* ************************************************************************** */
/*																			*/
/*														:::	 :::::::: */
/* launch_render.c									:+:	 :+:	:+: */
/*													+:+ +:+		 +:+	 */
/* By: xamartin <xamartin@student.le-101.fr>	 +#+ +:+	 +#+		*/
/*												+#+#+#+#+#+ +#+		 */
/* Created: 2020/04/15 17:32:30 by xamartin		 #+#	#+#			 */
/* Updated: 2020/04/23 15:01:36 by xamartin		 ### ########lyon.fr */
/*																			*/
/* ************************************************************************** */

#include "render.h"

/*
Need function to use:	- new gdata->win -> OK 
						- clear gdata->win -> glClear
						- put pixel -> glDrawPixel but not optim maybe create a texture see link 1
						- new image
						- get data addr
						- put image to gdata->win
						- get color value
						- loop / loop_hook / expose_hook / key_hook / mous_hook
						- auto replay for hook
						- put string
						- xpm to image
						- destroy image
						- swap buffer -> flushGLContext
						- change context -> selectGLContext
						
1 - http://www.multigesture.net/articles/how-to-draw-pixels-to-a-texture-opengl/
TO DO:
		- put pixel (char-RGB) in a texture of the size of a screen
		- draw lines
		- load img (xpm free to use else code it or change imaeg type to xpm)
		- create image (load image and put it in a texture)
		- multi screen in gdata->wins
		- change screen (context)
		MATRIX:
		- create a lib to computate matrix
		- mutliply
		- add
		- pow
		MENU: 
		- create rect | circle | fonts -> for menus
		- create hit box for button and other things
add things when we things about it
*/

void		error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

// pas de librarie de:	- matrixes
// 						- 3d
//						- load shader
// ok vertex
void		terminate_reader(t_gdata *gdata)
{
	glfwDestroyWindow(gdata->win);
	// need to free gdata->obj | gdata->mtl
	glfwTerminate();
}

static const float vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		 0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};


int render1(t_gdata *gdata)
{	
	init_shader(gdata->engine);

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

 	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

 	create_texture(gdata, "data/ressources/bomm.jpg", 0);
 	create_texture(gdata, "data/ressources/mouth.jpg", 1);
	glUseProgram(gdata->engine->program);
	load_texture(gdata, "texture1", 0);
	load_texture(gdata, "texture2", 1);

	float		*tmp_data;
	t_matrix	*tmp;

	while (!glfwWindowShouldClose(gdata->win))
	{
		// glClearColor(0.25f, 0.0f, 0.5f, 0.5f);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[0]);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, gdata->engine->texture_id[1]);
		ft_printf(".");

		glUseProgram(gdata->engine->program);

		ft_printf(".");
		gdata->engine->projection = init_identity_matrix4x4();
		perspective_matrix4x4(gdata->engine->projection, degree_to_radians(gdata->engine->fov), (W / (float)H), 0.1f, 100.0f);
		unsigned int projectionLoc = glGetUniformLocation(gdata->engine->program, "projection");
		tmp_data = transform_matrix4x4_to_float(gdata->engine->projection);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, (GLfloat*)tmp_data);
		free(tmp_data);

		ft_printf(".");
		gdata->engine->camera_tmp[0] = gdata->engine->camera_pos[0] - gdata->engine->camera_front[0];
		gdata->engine->camera_tmp[1] = gdata->engine->camera_pos[1] - gdata->engine->camera_front[1];
		gdata->engine->camera_tmp[2] = gdata->engine->camera_pos[2] - gdata->engine->camera_front[2];

		gdata->engine->view = init_identity_matrix4x4();
		look_at_matrix4x4(gdata->engine->view, gdata->engine->camera_pos,
		gdata->engine->camera_tmp, gdata->engine->camera_up);

		unsigned int viewLoc = glGetUniformLocation(gdata->engine->program, "view");
		tmp_data = transform_matrix4x4_to_float(gdata->engine->view);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (GLfloat*)tmp_data);
		ft_printf(".");
		free(tmp_data);
		
		glBindVertexArray(VAO);

		gdata->engine->model = init_identity_matrix4x4();
		tmp = init_identity_matrix4x4();
		translate_matrix4x4(tmp, 0.0f, 0.0f, 0.0f);
		rotate_matrix4x4_y(gdata->engine->model, tmp, sin(glfwGetTime()));
		unsigned int modelLoc = glGetUniformLocation(gdata->engine->program, "model");
		tmp_data = transform_matrix4x4_to_float(gdata->engine->model);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (GLfloat*)tmp_data);
		free(tmp_data);
		ft_printf(".");

		glDrawArrays(GL_TRIANGLES, 0, 36);
		ft_printf(".");

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
