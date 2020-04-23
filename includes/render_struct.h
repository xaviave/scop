/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:16:09 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/23 19:26:46 by xamartin         ###   ########lyon.fr   */
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

# define GL_GLEXT_PROTOTYPES

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
	// one matrix per object to move them individually ?
	// center of each object
	// apply on every point with move_matrix()
	t_matrix				*model;
	// env move everything
	t_matrix				*env;
	
	float					camera_up[3];
	float					camera_pos[3];
	float					camera_tmp[3];
	float					camera_front[3];
	
	unsigned int			texture_id[32];
	float					fov;
	float					yaw;
	float					pitch;
	float					last_x;
	float					last_y;
	float					sensitivity;
	float					last_frame;
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
