/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:44:41 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 13:51:40 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H

# include "scop.h"

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  include "../external_lib/glfw/deps/linmath.h"
#  include <GLFW/glfw3.h>
# else
#  include "../external_lib/glfw/deps/linmath.h"
#  include "../external_lib/glfw/deps/glad/gl.h"
#  include <GLFW/glfw3.h>
# endif

# define SHADER_READ 1000

# define M_ENG_ 10
# define M_BUF_ 11

typedef struct				s_matrix
{
	int						rows;
	int						columns;
	float					**values;
}							t_matrix;

/*
** *projection;
** put the world in the camera view
** projection matrix 1x4 = (degree_to_rs) and 30° (quite zoomed in)
**
** *view;
** to put the model on the worl
**
** *model;
** one matrix per object to move them individually ?
** center of each object
** apply on every point with move_matrix()
*/

typedef struct				s_engine
{
	t_matrix				*projection;
	t_matrix				*view;
	t_matrix				*model;
	float					camera_up[3];
	float					camera_pos[3];
	float					camera_tmp[3];
	float					camera_front[3];
	GLuint					texture_id;
	float					fov;
	float					yaw;
	float					pitch;
	float					last_x;
	float					last_y;
	int						fix;
	float					sensitivity;
	float					last_frame;
	float					max[2];
	float					angle;
	int						rotate;
	int						grey;
	int						sample;
	int						texture;
	int						random;
	GLuint					program;
	GLuint					mvp_location;
}							t_engine;

typedef struct				s_buffer
{
	unsigned int			vao;
	unsigned int			vbo_vertices;
	unsigned int			vbo_indices;
	unsigned int			grey_loc;
	unsigned int			sample_loc;
	unsigned int			random_loc;
	unsigned int			texture_loc;
}							t_buffer;

typedef struct				s_gdata
{
	int						nb_objs;
	t_obj					*obj;
	t_mtl					*mtl;
	GLFWwindow				*win;
	t_buffer				*buffer;
	t_engine				*engine;
	double					time;
	float					*vertices;
	int						actual_obj;
	t_addr					*addr;
}							t_gdata;

#endif
