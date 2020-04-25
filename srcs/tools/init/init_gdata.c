/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 16:52:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	init_graphic_context(t_gdata *gdata)
{
	if (!glfwInit())
		return (0);
	glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	gdata->win = glfwCreateWindow(W, H, PROG_NAME, NULL, NULL);
	if (!gdata->win)
		return (0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_REFRESH_RATE, 30);
	glfwSetInputMode(gdata->win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(gdata->win, key_callback);
	glfwSetCursorPosCallback(gdata->win, mouse_callback);
	glfwMakeContextCurrent(gdata->win);
    glfwSwapInterval(1);
	return (1);
}

void		reset(t_gdata *gdata)
{
	gdata->engine->grey = 0;
	gdata->engine->random = 0;
	gdata->engine->texture = 0;
	gdata->engine->fix = 1;
	gdata->engine->rotate = 0;
	gdata->engine->angle = degree_to_radians(90);
	gdata->engine->fov = 45.0f;
	gdata->engine->camera_pos[0] = gdata->engine->max[0];
	gdata->engine->camera_pos[2] = gdata->engine->max[1];
}

static int	init_engine(t_gdata *gdata)
{
	gdata->engine->fix = 1;
	gdata->engine->last_x = 0.0f;
	gdata->engine->last_y = 0.0f;
	gdata->engine->fov = 45.0f;
	gdata->engine->yaw = 0.0f;
	gdata->engine->pitch = 0.0f;
	gdata->engine->sensitivity = 0.05f;
	ft_bzero(gdata->engine->camera_up, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_pos, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_tmp, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_front, sizeof(float[3]));
	gdata->engine->camera_up[1] = 1.0f;
	gdata->engine->last_frame = glfwGetTime();
	return (1);
}

int			init_gdata(t_gdata *gdata, t_parser *parser)
{
	if (!init_graphic_context(gdata))
		return (0);
    gdata->nb_objs = parser->nb_args;
    gdata->obj = parser->obj;
    gdata->mtl = parser->mtl;
	if (!(gdata->engine = (t_engine *)malloc(sizeof(t_engine))))
		return (0);
	if (!(gdata->buffer = (t_buffer *)malloc(sizeof(t_buffer))))
		return (0);
	if (!init_engine(gdata) || !init_all_obj(gdata) ||
		!init_shader(gdata->engine) || !init_buffer(gdata))
		return (0);
	glEnable(GL_DEPTH_TEST);
	reset(gdata);
	return (1);
}
