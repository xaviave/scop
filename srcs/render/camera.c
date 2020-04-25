/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:06:19 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 16:53:49 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void			create_texture_data(t_gdata *gdata, t_matrix *m, char *name)
{
	float			*tmp_data;
	unsigned int	loc_data;

	loc_data = glGetUniformLocation(gdata->engine->program, name);
	tmp_data = transform_matrix4x4_to_float(m);
	glUniformMatrix4fv(loc_data, 1, GL_FALSE, (GLfloat*)tmp_data);
	free(tmp_data);
}

static void			fix_camera(t_gdata *gdata)
{
	if (!gdata->engine->fix)
	{
		gdata->engine->camera_tmp[0] =
			gdata->engine->camera_pos[0] - gdata->engine->camera_front[0];
		gdata->engine->camera_tmp[1] =
			gdata->engine->camera_pos[1] - gdata->engine->camera_front[1];
		gdata->engine->camera_tmp[2] =
			gdata->engine->camera_pos[2] - gdata->engine->camera_front[2];
	}
	else
	{
		gdata->engine->camera_tmp[0] = gdata->engine->camera_front[0];
		gdata->engine->camera_tmp[1] = gdata->engine->camera_front[1];
		gdata->engine->camera_tmp[2] = gdata->engine->camera_front[2];
	}	
}

void				update_matrix(t_gdata *gdata)
{
	t_matrix		*tmp;
	
	glUseProgram(gdata->engine->program);
	gdata->engine->projection = init_identity_matrix4x4();
	perspective_matrix4x4(gdata->engine->projection, degree_to_radians(gdata->engine->fov), (W / (float)H), 0.1f, 100.0f);
	create_texture_data(gdata, gdata->engine->projection, "projection");
	gdata->engine->view = init_identity_matrix4x4();
	fix_camera(gdata);
	look_at_matrix4x4(gdata->engine->view, gdata->engine->camera_pos,
	gdata->engine->camera_tmp, gdata->engine->camera_up);
	create_texture_data(gdata, gdata->engine->view, "view");
	gdata->engine->model = init_identity_matrix4x4();
	tmp = init_identity_matrix4x4();
	gdata->engine->angle = glfwGetTime();
	translate_matrix4x4(tmp, 0.0f, 0.0f, 0.0f);
	if (gdata->engine->rotate == 1)
		rotate_matrix4x4_x(gdata->engine->model, tmp, gdata->engine->angle);
	else if (gdata->engine->rotate == 2)
		rotate_matrix4x4_y(gdata->engine->model, tmp, gdata->engine->angle);
	else if (gdata->engine->rotate == 3)
		rotate_matrix4x4_z(gdata->engine->model, tmp, gdata->engine->angle);
	else
		rotate_matrix4x4_y(gdata->engine->model, tmp, 90);
	create_texture_data(gdata, gdata->engine->model, "model");
	free_matrix(tmp);
}