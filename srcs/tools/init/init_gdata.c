/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 17:20:43 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "render.h"

static int	init_graphic_context(t_gdata *gdata)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	gdata->win = glfwCreateWindow(W, H, PROG_NAME, NULL, NULL);
	if (!gdata->win)
		return (0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);
	glfwSetKeyCallback(gdata->win, key_callback);
	glfwSetCursorPosCallback(gdata->win, mouse_callback);
	glfwMakeContextCurrent(gdata->win);
    glfwSwapInterval(1);
	return (1);
}

void		create_indices(t_obj *obj)
{
	int		i;
	int		j;
	int		nu;
	int		v_id;

	v_id = -1;
	i = -1;
	nu = 0;
	while (++i < obj->len_faces)
	{
		nu += 3;
		if (obj->faces[i].nb_vertexes == 4)
			nu += 3;
	}
	obj->size_indices = nu;
	obj->indices = malloc(sizeof(float) * nu);
	i = -1;
	while (++i < obj->len_faces)
	{
		j = -1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[0] - 1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[1] - 1;
		obj->indices[++v_id] = obj->faces[i].vertexes_id[2] - 1;
		if (obj->faces[i].nb_vertexes == 4)
		{
			obj->indices[++v_id] = obj->faces[i].vertexes_id[0] - 1;
			obj->indices[++v_id] = obj->faces[i].vertexes_id[2] - 1;
			obj->indices[++v_id] = obj->faces[i].vertexes_id[3] - 1;
		}
	}
}

void		create_vertices(t_obj *obj)
{
	int		i;
	int		v_id;
	
	i = -1;
	v_id = -1;
	obj->size_vertices = obj->len_vertexes * 6;
	if (!(obj->vertices = malloc(sizeof(float) * obj->size_vertices)))
		return ;
	while (++i < obj->len_vertexes)
	{
		obj->vertices[++v_id] = obj->vertexes[i].x;
		obj->vertices[++v_id] = obj->vertexes[i].y;
		obj->vertices[++v_id] = obj->vertexes[i].z;
		obj->vertices[++v_id] = obj->vertexes[i].x;
		obj->vertices[++v_id] = obj->vertexes[i].y;
		obj->vertices[++v_id] = obj->vertexes[i].z;
	}
}

int			init_gdata(t_gdata *gdata, t_parser *parser)
{
    gdata->obj = parser->obj;
    gdata->mtl = parser->mtl;
	create_vertices(&gdata->obj[0]);
	create_indices(&gdata->obj[0]);
	if (!(gdata->engine = (t_engine *)malloc(sizeof(t_engine))))
		return (0);
	gdata->engine->last_x = 0.0f;
	gdata->engine->last_y = 0.0f;
	gdata->engine->fov = 85.0f;
	gdata->engine->yaw = 0.0f;
	gdata->engine->pitch = 0.0f;
	gdata->engine->sensitivity = 0.05f;
	ft_bzero(gdata->engine->camera_up, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_pos, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_tmp, sizeof(float[3]));
	ft_bzero(gdata->engine->camera_front, sizeof(float[3]));
	gdata->engine->camera_up[1] = 1.0f;
	gdata->engine->camera_pos[2] = 3.0f;
	gdata->engine->camera_front[2] = -1.0f;
	gdata->engine->last_frame = glfwGetTime();
	return (init_graphic_context(gdata));
}
