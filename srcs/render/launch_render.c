/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:32:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/15 19:02:09 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
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
						- change context ->  selectGLContext
						
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

void		key_callback(GLFWwindow *win, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
}

void		terminate_reader(t_gdata *gdata)
{
	glfwDestroyWindow(gdata->win);
	// need to free gdata->obj | gdata->mtl
	glfwTerminate();
}

void		render(t_gdata *gdata)
{
	float	ratio;
	mat4x4	m, p, mvp;
    int 	width, height;
	GLuint	vertex_buffer, vertex_shader, fragment_shader, program;
    GLint	mvp_location, vpos_location, vcol_location;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
 
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
 
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
 
    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");
 
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));
	while (!glfwWindowShouldClose(gdata->win))
	{

        glfwGetFramebufferSize(gdata->win, &width, &height);
        ratio = width / (float) height;
 
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
 
        mat4x4_identity(m);
        mat4x4_rotate_Z(m, m, (float) glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);
 
        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);
 
        glfwSwapBuffers(gdata->win);
		glfwWaitEvents();
		ft_printf("ue");
	}
	terminate_reader(gdata);
}

void		error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int         launch_render(t_gdata *gdata, t_parser *parser)
{
    if (!init_gdata(gdata, parser))
		return (0);
	render(gdata);
	return (1);
}