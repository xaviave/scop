/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/19 22:07:20 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** C library
*/

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

/*
** External Libraries
*/
 
# include "../libft/header/libft.h"
# include <SDL2/SDL.h>

/*
** Internal Libraries
*/

# include "cleaner.h"
# include "error.h"
# include "tools.h"

/*
** Defines
*/

# define PROG_NAME "Scop"

/*
** Structures
*/

/*
** t_vertex defines a geometrical vertex.
** parsing: v x, y, z[, w]
*/

typedef struct      s_vertex
{
	float			x;
	float			y;
	float			z;
	float			w; // optionnal | default value 1.0
}					t_vertex;

/*
** t_texture defines the texture's coordinate.
** parsing: vp u, [, v, w]
*/

typedef struct		s_texture
{
	float			u;
	float			v; //need to be between 0 and 1 | default 0
	float			w; //need to be between 0 and 1 | default 0
}					t_texture;

/*
** t_normal defines the vertex normals
** parsing: vn x y z
*/

typedef struct		s_normal
{
	float			x;
	float			y;
	float			z;
}					t_normal;

/*
** t_space_vertexs defines the paramter space vertexs.
** Define points in parameter space of a curve or surface.
** parsing: vp u [,v] [,w]
*/

typedef struct		s_space_vertex
{
	float			u;
	float			v; 
	float			w;
}					t_space_vertex;

/*
** t_face defines a ploygonal face element.
** Faces are defined using lists of vertex, texture and normal indices.
** parsing: f v1 v2[/vt2] v3[//vn3] v4[/vt4][/vn4] ...
*/

typedef struct		s_face
{
	int				nb; // nb of ?
}					t_face;

/*
** t_line defines a polyline element.
** parsing: l v1 v2 v3
*/

typedef struct		s_line
{
	int				nb; // nb of ?
}					t_line;

/*
** t_obj have all the components of an obj.
*/

typedef struct		s_obj
{
	char			*mtllib;
	char			*usemtl;
	
	t_face			*faces;
	t_line			*lines;
	t_normal		*normals;
	t_space_vertex	*space_vertexes;
	t_texture		*textures;
	t_vertex		*vertexes;
}					t_obj;

typedef struct      s_prog
{
	int             exit_state;
	SDL_Window      *win;
	SDL_Event       ev;
}                   t_prog;

/*
** Functions
*/

#endif
