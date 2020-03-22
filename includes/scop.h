/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 17:47:47 by xamartin         ###   ########lyon.fr   */
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
# define GLEW_STATIC // useless ?
# include <GLEW/glew.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_opengl.h>
# include <OpenGl/gl.h>

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
	double			x;
	double			y;
	double			z;
	double			w; // optionnal | default value 1.0
}					t_vertex;

/*
** t_texture defines the texture's coordinate.
** parsing: vt u[, v, w]
*/

typedef struct		s_texture
{
	int				id;
	double			u;
	double			v; //need to be between 0 and 1 | default 0
	double			w; //need to be between 0 and 1 | default 0
}					t_texture;

/*
** t_normal defines the vertex normals
** parsing: vn x y z
*/

typedef struct		s_normal
{
	int				id;
	double			x;
	double			y;
	double			z;
}					t_normal;

/*
** t_face defines a polygonal face element.
** Faces are defined using lists of vertex, texture and normal indices.
** parsing: f v1 v2[/vt2] v3[//vn3] v4[/vt4][/vn4] ...
*/

typedef struct		s_face
{
	int				id;
	int				nb_vertexes;
	int				*vertexes_id;
	int				*textures_id;
	int				*normals_id;
}					t_face;

/*
** t_line defines a polyline element.
** parsing: l v1 v2 v3
*/

typedef struct		s_line
{
	int				id;
	int				nb_vertexes;
	int				*vertexes_id;
}					t_line;

/*
**
*/

typedef struct		s_group
{
	int				id;
	int				type;
	int				nb_entity;
	int				first_entity;
	char			*name;
}					t_group;

/*
** 
*/

typedef struct		s_object
{
	int				id;
	int				type;
	int				nb_entity;
	int				first_entity;
	char			*name;
}					t_object;

/*
** t_obj have all the components of an obj.
*/

typedef struct		s_obj
{
	int				id;
	int				error;
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
    SDL_GLContext   gl_context;
}                   t_prog;

/*
** Functions
*/

/*
** Render.h
*/


# define W 640
# define H 480

# define True 1
# define False 0


int         launch_render(t_prog *p);

/*
** Parser.h
*/

/*
** Structures
*/

typedef struct		s_parser
{
	int				nb_args;
	char			**args;
	t_obj			*obj;
}					t_parser;


/*
** Functions
*/

int				    launch_parser(t_parser *parser,  int ac, char **av);
void				reader(t_parser *parser);

int					check_raw_data(char *raw_data);

void				parser_vt(t_obj *obj, char *raw_data);
void				parser_vn(t_obj *obj, char *raw_data);
void				parser_v(t_obj *obj, char *raw_data);
void				parser_f(t_obj *obj, char *raw_data);
void				parser_l(t_obj *obj, char *raw_data);
void				parser_mtl_pass(t_obj *obj, char *raw_data);
void				parser_o(t_obj *obj, char *raw_data, int id, int type, int nb_id);
void				parser_g(t_obj *obj, char *raw_data, int id, int type, int nb_id);

/*
** Tools.h
*/

/*
** Structures
*/

typedef struct				s_list_parser
{
    short           		id; // id define the first type of objects
	char					*data;
	struct s_list_parser	*next;
}							t_list_parser;

/*
** Functions
*/

int							list_parser_len(t_list_parser **list);
void						add_list_parser(t_list_parser **list, char *raw_data);

int							get_lenght_entity(t_list_parser *list, int id);
int							len_list_parser_id(t_list_parser *list, int id);

void                		init_obj(t_obj *obj);
void						init_obj_ptr(t_obj *obj, t_list_parser *list);

void						init_parser_ptr(void (*f[7])(t_obj *, char *));

void						init_parser(t_parser *parser, int ac, char **av);

int							pass_whitespace_number(int i,char *str);

int							pass_whitespace_double(int i,char *str);

int							pass_whitespace(int i,char *str);

double						optional_value_double(char *str, double d);

double						ft_atof(char *str);

#endif
