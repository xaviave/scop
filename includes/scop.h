/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 17:10:25 by xavier_mart      ###   ########lyon.fr   */
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
	int				id;
	float			x;
	float			y;
	float			z;
	float			w; // optionnal | default value 1.0
}					t_vertex;

/*
** t_texture defines the texture's coordinate.
** parsing: vt u[, v, w]
*/

typedef struct		s_texture
{
	int				id;
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
	int				id;
	float			x;
	float			y;
	float			z;
}					t_normal;

/*
** t_space_vertexs defines the paramter space vertexs.
** Define points in parameter space of a curve or surface.
** parsing: vp u, v[, w]
*/

typedef struct		s_space_vertex
{
	int				id;
	float			u;
	float			v; 
	float			w; // default to 1.0
}					t_space_vertex;

/*
** t_face defines a ploygonal face element.
** Faces are defined using lists of vertex, texture and normal indices.
** parsing: f v1 v2[/vt2] v3[//vn3] v4[/vt4][/vn4] ...
*/

typedef struct		s_face
{
	int				id;
	int				nb; // nb of ?
}					t_face;

/*
** t_line defines a polyline element.
** parsing: l v1 v2 v3
*/

typedef struct		s_line
{
	int				id;
	int				nb; // nb of ?
}					t_line;

/*
**
*/

typedef struct		s_group
{
	int				id;
	char			*name;
}					t_group;

/*
** 
*/

typedef struct		s_object
{
	int				id;
	char			*name;
}					t_object;

/*
** t_obj have all the components of an obj.
*/

typedef struct		s_obj
{
	int				id;
	char			*mtllib;
	char			*usemtl;

	t_face			*faces;
	int				len_faces;

	t_group			*groups;
	int				len_groups;

	t_line			*lines;
	int				len_lines;

	t_normal		*normals;
	int				len_normals;

	t_object		*objects;
	int				len_objects;

	t_space_vertex	*space_vertexes;
	int				len_space_vertexes;

	t_texture		*textures;
	int				len_textures;
	
	t_vertex		*vertexes;
	int				len_vertexes;
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
