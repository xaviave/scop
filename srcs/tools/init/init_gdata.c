/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 15:48:24 by xamartin         ###   ########lyon.fr   */
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

void		add_vertices(t_obj *obj, t_face face, int *v_id, int f_id)
{
	int		id;

	id = face.vertexes_id[f_id];
	obj->vertices[*v_id] = obj->vertexes[id].x;
	obj->vertices[*v_id + 1] = obj->vertexes[id].y;
	obj->vertices[*v_id + 2] = obj->vertexes[id].z;
	*v_id += 3;
	if (face.has_texture)
	{
		id = face.textures_id[f_id];
		obj->vertices[*v_id] = obj->textures[id].u;
		obj->vertices[*v_id + 1] = obj->textures[id].v;
		obj->vertices[*v_id + 2] = obj->textures[id].w;
		*v_id += 3;
	}
	if (face.has_normal)
	{
		id = face.normals_id[f_id];
		obj->vertices[*v_id] = obj->vertexes[id].x;
		obj->vertices[*v_id + 1] = obj->vertexes[id].y;
		obj->vertices[*v_id + 3] = obj->vertexes[id].z;
		*v_id += 3;
	}
}

void		create_face(t_obj *obj, t_face face, int *v_id, int option)
{
	int		id;

	id = (!option) ? 0 : 2; 
	add_vertices(obj, face, v_id, id);
	id = (!option) ? 1 : 3; 
	add_vertices(obj, face, v_id, id);
	id = (!option) ? 2 : 0; 
	add_vertices(obj, face, v_id, id);
}

// void		create_vertices(t_obj *obj)
// {
// 	int		i;
// 	int		v_id;

// 	v_id = 0;
// 	i = -1;
// 	obj->vertices = malloc(sizeof(float[1024]));
// 	while (++i < obj->len_faces)
// 	{
// 		create_face(obj, obj->faces[i], &v_id, 0);
// 		if (obj->faces->nb_vertexes == 4)
// 			create_face(obj, obj->faces[i], &v_id, 1);
// 	}
// }

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
		nu += obj->faces[0].nb_vertexes;
	obj->indices = malloc(sizeof(float) * nu);
	i = -1;
	while (++i < obj->len_faces)
	{
		j = -1;
		while (++j < obj->faces[i].nb_vertexes)
			obj->indices[++v_id] = obj->faces[i].vertexes_id[j];
	}
}

void		create_vertices(t_obj *obj)
{
	int		i;
	int		v_id;
	
	i = -1;
	v_id = -1;
	obj->vertices = malloc(sizeof(float) * obj->len_vertexes * 3);
	while (++i < obj->len_vertexes)
	{
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
