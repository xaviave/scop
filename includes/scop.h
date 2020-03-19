/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/19 21:27:02 by xavier_mart      ###   ########lyon.fr   */
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
** t_vertice defines a geometrical vertice
*/

typedef struct      s_vertice
{
	float			x;
	float			y;
	float			z;
	float			w; // optionnal | default value 1.0
}					t_vertice;

/*
** t_texture defines the texture's coordinate
*/

typedef struct		s_texture
{
	float			u;
	float			v; //need to be between 0 and 1 | default 0
	float			w; //need to be between 0 and 1 | default 0
}					t_texture;

/*
** t_normal defines the vertex normals
*/

typedef struct		s_normal
{
	float			x;
	float			y;
	float			z;
}					t_normal;

/*
** t_space_vertices defines the paramter space vertices
*/

typedef struct		s_space_vertice
{
	float			u;
	float			v;
	float			w;
}					t_space_vertice;

/*
** t_face defines a ploygonal face element
*/

typedef struct		s_face
{
	int				nb; // nb of ?
}					t_face;

/*
** t_line defines a line element
*/

typedef struct		s_line
{
	int				nb; // nb of ?
}					t_line;

/*
** t_obj have all the components of an obj
*/

typedef struct		s_obj
{
	t_face			*faces;
	t_line			*lines;
	t_normal		*normals;
	t_space_vertice	*space_vertices;
	t_texture		*textures;
	t_vertice		*vertices;
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
