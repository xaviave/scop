/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:06:19 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/25 17:20:58 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int			create_texture_data(t_gdata *gdata, t_matrix *m, char *name)
{
	float			*tmp_data;
	unsigned int	loc_data;

	loc_data = glGetUniformLocation(gdata->engine->program, name);
	if (!(tmp_data = transform_matrix4x4_to_float(m)))
        return (0);
	glUniformMatrix4fv(loc_data, 1, GL_FALSE, (GLfloat*)tmp_data);
	ft_memdel((void **)&tmp_data);
	return (1);
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

static int 			update_matrix_angle(t_gdata *gdata)
{
    t_matrix        *tmp;

    if (!(tmp = init_identity_matrix4x4(NULL)))
        return (0);
    translate_matrix4x4(tmp, 0.0f, 0.0f, 0.0f);
    if (gdata->engine->rotate == 1)
    {
        if (!(rotate_matrix4x4_x(gdata->engine->model, tmp, gdata->engine->angle)))
            return (0);
    }
    else if (gdata->engine->rotate == 2)
    {
        if (!(rotate_matrix4x4_y(gdata->engine->model, tmp, gdata->engine->angle)))
            return (0);
    }
    else if (gdata->engine->rotate == 3)
    {
        if (!(rotate_matrix4x4_z(gdata->engine->model, tmp, gdata->engine->angle)))
            return (0);
    }
    else if (!(rotate_matrix4x4_y(gdata->engine->model, tmp, 90)))
        return (0);
    if (!(create_texture_data(gdata, gdata->engine->model, "model")))
        return (0);
    return (free_matrix(tmp) == NULL ? 1 : 1);
}

int 				update_matrix(t_gdata *gdata)
{
	glUseProgram(gdata->engine->program);
	if (!(gdata->engine->projection = init_identity_matrix4x4(
	        gdata->engine->projection)))
        return (0);
	perspective_matrix4x4(gdata->engine->projection, degree_to_radians(
	        gdata->engine->fov), (W / (float)H), 0.1f, 100.0f);
	if (!(create_texture_data(gdata, gdata->engine->projection, "projection")))
	    return (0);
	if (!(gdata->engine->view = init_identity_matrix4x4(gdata->engine->view)))
        return (0);
	fix_camera(gdata);
	look_at_matrix4x4(gdata->engine->view, gdata->engine->camera_pos,
	gdata->engine->camera_tmp, gdata->engine->camera_up);
	if (!(create_texture_data(gdata, gdata->engine->view, "view")))
	    return (0);
	if (!(gdata->engine->model = init_identity_matrix4x4(gdata->engine->model)))
	    return (0);
    gdata->engine->angle = glfwGetTime();
    if (!(update_matrix_angle(gdata)))
        return (0);
    return (1);
}