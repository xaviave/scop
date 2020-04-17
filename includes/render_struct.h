/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:16:09 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 21:49:08 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H

# include "scop.h"

# ifdef __APPLE__
# define GL_SILENCE_DEPRECATION
# include "../external_lib/glfw/deps/linmath.h"
# include <GLFW/glfw3.h>
# else
# include "../lib/glfw/deps/linmath.h"
# include <GLFW/glfw3.h>
# endif

static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
 
static const char* fragment_shader_text =
"#version 110\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";


static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};

typedef struct				s_matrix
{
	int						rows;
	int						columns;
	float					**values;
}							t_matrix;


typedef struct				s_engine
{
	// put the world in the camera view
	// projection matrix 1x4 = (degree_to_rs) and 30° (quite zoomed in)
	t_matrix				*projection;
	// to put the model on the worl
	t_matrix				*view;
	// one matrix per obkect to move them individually ?
	// center of each object
	// apply on every point with move_matrix()
	// 
	t_matrix				*model_obj_matrix;
	// env move everything
	t_matrix				*env;
	float					camera[3];
	GLuint					program;
	GLuint					mvp_location;
}							t_engine;

typedef struct      		s_gdatas
{
	t_obj					*obj;
	t_mtl					*mtl;
	GLFWwindow				*win;
	t_engine				*engine;
	double					time;
}                   		t_gdata;

#endif
