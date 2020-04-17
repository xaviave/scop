/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 20:58:40 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "render.h"

static void	init_program(t_engine *e, GLuint vs, GLuint fs)
{
	GLuint	vpos_location;
	GLuint	vcol_location;

    e->program = glCreateProgram();
    glAttachShader(e->program, vs);
    glAttachShader(e->program, fs);
    glLinkProgram(e->program);
    e->mvp_location = glGetUniformLocation(e->program, "MVP");
    vpos_location = glGetAttribLocation(e->program, "vPos");
    vcol_location = glGetAttribLocation(e->program, "vCol");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));
}

void		init_shader(t_engine *e)
{
	GLuint	vs;
	GLuint	fs;
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader_text, NULL);
    glCompileShader(vs);
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader_text, NULL);
    glCompileShader(fs);
	init_program(e, vs, fs);
}

static int	init_graphic_context(t_gdata *gdata)
{
	GLuint	vb;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (0);	
	gdata->win = glfwCreateWindow(W, H, PROG_NAME, NULL, NULL);
	if (!gdata->win)
		return (0);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);
	glfwSetKeyCallback(gdata->win, key_callback);
	glfwMakeContextCurrent(gdata->win);
    glfwSwapInterval(1);
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// glViewport(0, 0, W, H);
	init_shader(&gdata->engine);
	return (1);
}

int			init_gdata(t_gdata *gdata, t_parser *parser)
{
    gdata->obj = parser->obj;
    gdata->mtl = parser->mtl;
	if (!(gdata->engine = (t_engine *)malloc(sizeof(t_engine))))
		return (0);
	return (init_graphic_context(gdata));
}
