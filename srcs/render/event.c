/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:34:59 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:16 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void	process_mouse(t_gdata *gdata)
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

static void	input_w_s_rotate(t_gdata *gdata, float camera_speed)
{
	float	tmp[3];

	ft_bzero(tmp, sizeof(float[3]));
	if (glfwGetKey(gdata->win, GLFW_KEY_S) == GLFW_PRESS &&
		!gdata->engine->fix)
	{
		vertex3_mul_float(tmp, gdata->engine->camera_front, camera_speed);
		vertex3_add(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_W) == GLFW_PRESS &&
		!gdata->engine->fix)
	{
		vertex3_mul_float(tmp, gdata->engine->camera_front, camera_speed);
		vertex3_sub(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_1) == GLFW_PRESS)
		gdata->engine->rotate = 0;
	if (glfwGetKey(gdata->win, GLFW_KEY_2) == GLFW_PRESS)
		gdata->engine->rotate = 1;
	if (glfwGetKey(gdata->win, GLFW_KEY_3) == GLFW_PRESS)
		gdata->engine->rotate = 2;
	if (glfwGetKey(gdata->win, GLFW_KEY_4) == GLFW_PRESS)
		gdata->engine->rotate = 3;
}

static void	input_a_d_grey(t_gdata *gdata, float camera_speed)
{
	float	tmp[3];

	ft_bzero(tmp, sizeof(float[3]));
	if (glfwGetKey(gdata->win, GLFW_KEY_A) == GLFW_PRESS && !gdata->engine->fix)
	{
		vertex3_mul_cross(tmp, gdata->engine->camera_front,
			gdata->engine->camera_up);
		vertex3_norm(tmp, tmp);
		vertex3_mul_float(tmp, tmp, camera_speed);
		vertex3_sub(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_D) == GLFW_PRESS && !gdata->engine->fix)
	{
		vertex3_mul_cross(tmp, gdata->engine->camera_front,
			gdata->engine->camera_up);
		vertex3_norm(tmp, tmp);
		vertex3_mul_float(tmp, tmp, camera_speed);
		vertex3_add(gdata->engine->camera_pos, gdata->engine->camera_pos, tmp);
	}
	if (glfwGetKey(gdata->win, GLFW_KEY_G) == GLFW_PRESS)
		gdata->engine->grey = (!gdata->engine->grey ? 1 : 0);
	if (glfwGetKey(gdata->win, GLFW_KEY_T) == GLFW_PRESS)
		gdata->engine->texture = (!gdata->engine->texture ? 1 : 0);
	if (glfwGetKey(gdata->win, GLFW_KEY_E) == GLFW_PRESS)
		gdata->engine->random = (!gdata->engine->random ? 1 : 0);
}

static void	input_move_shift_ctrl(t_gdata *gdata)
{
	if (glfwGetKey(gdata->win, GLFW_KEY_F) == GLFW_PRESS)
		gdata->engine->fix = (!gdata->engine->fix ? 1 : 0);
	if (glfwGetKey(gdata->win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		gdata->engine->camera_pos[1] += 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		gdata->engine->camera_pos[1] -= 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_LEFT) == GLFW_PRESS)
		gdata->engine->camera_pos[0] += 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		gdata->engine->camera_pos[0] -= 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_UP) == GLFW_PRESS)
		gdata->engine->camera_pos[2] += 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_DOWN) == GLFW_PRESS)
		gdata->engine->camera_pos[2] -= 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_R) == GLFW_PRESS)
		reset(gdata);
	if (glfwGetKey(gdata->win, GLFW_KEY_UP) == GLFW_PRESS &&
		gdata->engine->fov < 90)
		gdata->engine->fov += 0.25;
	if (glfwGetKey(gdata->win, GLFW_KEY_DOWN) == GLFW_PRESS &&
		gdata->engine->fov > 0)
		gdata->engine->fov -= 0.25;
}

void		handle_event(t_gdata *gdata)
{
	float	current_frame;
	float	camera_speed;

	glfwPollEvents();
	current_frame = glfwGetTime();
	camera_speed = 2.5f * (current_frame - gdata->engine->last_frame);
	gdata->engine->last_frame = current_frame;
	if (glfwGetKey(gdata->win, GLFW_KEY_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (glfwGetKey(gdata->win, GLFW_KEY_P) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	input_w_s_rotate(gdata, camera_speed);
	input_a_d_grey(gdata, camera_speed);
	input_move_shift_ctrl(gdata);
	process_mouse(gdata);
}
