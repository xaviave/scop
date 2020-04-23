/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:25:13 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/23 19:23:35 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void process_mouse(t_gdata *gdata)
{
	double	xpos;
	double	ypos;
	float	xoffset;
	float	yoffset;
	float	tmp_front[3];

	glfwGetCursorPos(gdata->win, &xpos, &ypos);
	xoffset = xpos - gdata->engine->last_x;
	yoffset = gdata->engine->last_y - ypos;
	gdata->engine->last_x = xpos;
	gdata->engine->last_y = ypos;
	xoffset *= gdata->engine->sensitivity;
	yoffset *= gdata->engine->sensitivity;
	gdata->engine->yaw += xoffset;
	gdata->engine->pitch += yoffset;
	if (gdata->engine->pitch > 89.0f)
		gdata->engine->pitch = 89.0f;
	if (gdata->engine->pitch < -89.0f)
		gdata->engine->pitch = -89.0f;
	tmp_front[0] = cos(degree_to_radians(gdata->engine->yaw))
		* cos(degree_to_radians(gdata->engine->pitch));
	tmp_front[1] = sin(degree_to_radians(gdata->engine->pitch));
	tmp_front[2] = sin(degree_to_radians(gdata->engine->yaw))
		* cos(degree_to_radians(gdata->engine->pitch));
	vertex3_norm(gdata->engine->camera_front, tmp_front);
}

void	input_ws(t_gdata *gdata, float camera_speed)
{
	float	tmp[3];

	ft_bzero(tmp, sizeof(float[3]));
	if (glfwGetKey(gdata->win, GLFW_KEY_W) == GLFW_PRESS)
	{
		vertex3_mul_float(tmp, gdata->engine->camera_front, camera_speed);
		vertex3_add(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_S) == GLFW_PRESS)
	{
		vertex3_mul_float(tmp, gdata->engine->camera_front, camera_speed);
		vertex3_sub(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
}

void	input_ad(t_gdata *gdata, float camera_speed)
{
	float	tmp[3];

	ft_bzero(tmp, sizeof(float[3]));
	if (glfwGetKey(gdata->win, GLFW_KEY_A) == GLFW_PRESS)
	{
		vertex3_mul_cross(tmp, gdata->engine->camera_front, gdata->engine->camera_up);
		vertex3_norm(tmp, tmp);
		vertex3_mul_float(tmp, tmp, camera_speed);
		vertex3_sub(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_D) == GLFW_PRESS)
	{
		vertex3_mul_cross(tmp, gdata->engine->camera_front, gdata->engine->camera_up);
		vertex3_norm(tmp, tmp);
		vertex3_mul_float(tmp, tmp, camera_speed);
		vertex3_add(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
}

void		handle_event(t_gdata *gdata)
{
	float	current_frame;
	float	camera_speed;
	
	glfwPollEvents();
	current_frame = glfwGetTime();
	camera_speed = 1.0f * (current_frame - gdata->engine->last_frame);
	gdata->engine->last_frame = current_frame;
	input_ws(gdata, camera_speed);
	input_ad(gdata, camera_speed);
	process_mouse(gdata);
}