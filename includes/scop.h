/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/26 11:07:59 by xamartin         ###   ########lyon.fr   */
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

# define ID_VT 0
# define ID_VN 1
# define ID_V 2
# define ID_F 3
# define ID_L 4
# define ID_MTL 5
# define ID_ERR 6
# define ID_G 7
# define ID_O 8

# define ID_KA 0
# define ID_KD 1
# define ID_KS 2
# define ID_TF 3
# define ID_D 4
# define ID_NS 5
# define ID_SHARP 6
# define ID_NI 7
# define ID_OD 8
# define ID_BUMP 9
# define ID_DECAL 10
# define ID_ILLUM 11

# define P_OBJ 0
# define P_MTL 1

/*
** OBJECT DEFINITION
** http://paulbourke.net/dataformats/obj/
*/

/*
** t_vertex defines a geometrical vertex.
** parsing: v x, y, z[, w]
*/

typedef struct      s_vertex
{
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
	int				nb_vertexes;
	int				*vertexes_id;
}					t_line;

/*
**
*/

typedef struct		s_group
{
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

	char			**mtl;
	int				len_mtl;

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

/*
** MATERIAL TEXTURE DEFINITION
** http://paulbourke.net/dataformats/mtl/
*/

/*
** Define the texture option while call the referenced file
*/

typedef struct			s_texture_option
{
	short				blendu; // default on
	short				blendv; // default on
	double				boost;
}						t_texture_option;

/*
** Ambient color describes the ambiant refletivity of a color
*/

typedef struct			s_ambient_color
{
	// code: Ka | only rgb
	int					id;
	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given
	char				*tga_file;
	t_texture_option	*option;
}						t_ambiant_color;

/*
** Diffuse color describes the refletivity of a color
*/

typedef struct			s_diffuse_color
{
	// code: Kd | only rgb
	int					id;
	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given
	char				*tga_file;
	t_texture_option	*option;
}						t_diffuse_color;

/*
** Specular color describes the specular reflectivity of a color
*/

typedef struct			s_specular_color
{
	// code: Ks | only rgb
	int					id;
	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given
	char				*tga_file;
	t_texture_option	*option;
}						t_specular_color;

/*
** Transmission filter describes the specular reflectivity of a color
*/

typedef struct			s_transmission_filter
{
	// code: Tf | only rgb
	int					id;
	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given
	char				*tga_file;
	t_texture_option	*option;
}						t_transmission_filter;

/*
** Transparent discribes the amout this material dissolves int the background
*/

typedef struct			s_transparent
{
	// code: d
	int					id;
	short				halo; // default 0 | formula =1.0 - (N*v)(1.0-factor)
	float				factor; // between 0 and 1 | 1 is opaque
}						t_transparent;

/*
** Specular exponent describes the focus of the focus of the specular highlight
*/

typedef struct			s_specular_exponent
{
	// code: Ns
	int					id;
	double				value; // between 0 to 1000
}						t_specular_exponent;

/*
** Sharpness describes the reflections from the local reflection map
*/

typedef struct			s_sharpness
{
	// code: sharpness
	int					id;
	double				value; // between 0 to 1000 | default 60
}						t_sharpness;

/*
** Optical density describes the optical density for the surface
*/

typedef struct			s_optical_density
{
	// code: Ni
	int					id;
	double				value; // between 0.001 to 10
}						t_optical_density;

/*
** MATERIAL TEXTURE MAP
*/

/*
** 
*/

typedef struct			s_bump
{
	// code: bump
	int					id;
	char				*tga_file;
	t_texture_option	*option;
}						t_bump;

/*
** 
*/

typedef struct			s_disp
{
	// code: disp
	int					id;
	char				*tga_file;
	t_texture_option	*option;
}						t_disp;

/*
** 
*/

typedef struct			s_decal
{
	// code: decal | only rgb
	int					id;
	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given
	char				*tga_file;
	t_texture_option	*option;
}						t_decal;

/* 
	algorithm:
		0. Color on and Ambient off
		1. Color on and Ambient on
		2. Highlight on
		3. Reflection on and Ray trace on
		4. Transparency: Glass on, Reflection: Ray trace on
		5. Reflection: Fresnel on and Ray trace on
		6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
		7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
		8. Reflection on and Ray trace off
		9. Transparency: Glass on, Reflection: Ray trace off
		10. Casts shadows onto invisible surfaces
*/

/*
** 
*/

typedef struct			s_shading
{
	// code: illum | only rgb
	int					id;

	float				r; // between 0 and 1
	float				g; // equal to r if not given
	float				b; // equal to r if not given	int					type;
	void				(*f[12])(char *); // pointeru to the shading algorithm
}						t_shading;

typedef struct				s_mtl
{
	int						id;
	char					*name; //no space else error

	t_ambiant_color			*ac;
	int						len_ac;
	
	t_diffuse_color			*dc;
	int						len_dc;
	
	t_specular_color		*sc;
	int						len_sc;

	t_transmission_filter	*tf;
	int						len_tf;
	
	t_transparent			*t;
	int						len_t;

	t_specular_exponent		*se;
	int						len_se;
	
	t_sharpness				*sharpness;
	int						len_sharpness;

	t_optical_density		*od;
	int						len_od;

	t_bump					*bump;
	int						len_bump;

	t_decal					*decal;
	int						len_decal;
	
	t_shading				*s;
	int						len_s;
}							t_mtl;

/*
** Render structure definition
*/

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

# define TRUE 1
# define FALSE 0


int         launch_render(t_prog *p);


/*
** TOOLS.H
*/

/*
** Structures
*/

typedef struct				s_parser_option
{
	int						len[10];
	short					parsing_type;
	int						list_parser_len;
	int						index;
	char					*file;
	int						data_len;
}							t_parser_option;

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
void						add_list_parser(t_list_parser **list, char *raw_data,
	t_parser_option *opt);

int							len_list_parser_id(t_list_parser *list);

void                		init_obj(t_obj *obj, t_parser_option *opt);

void						init_mtl(t_mtl *mtl);
void						init_mtl_ptr(t_mtl *mtl, t_list_parser *list);

void						init_parser_obj_ptr(void (*f[7])(t_obj *, char *));
void						init_parser_mtl_ptr(void (*f[10])(t_mtl *, char *));

void						init_parser_option(t_parser_option *opt, char *file,
	int index, short parsing_type);

int							pass_whitespace_number(int i,char *str);
int							pass_whitespace_double(int i,char *str);
int							pass_whitespace(int i,char *str);

void						print_obj(t_obj *obj);

double						optional_value_double(char *str, double d);

double						ft_atof(char *str);

/*
** PARSER.H
*/

/*
** Structures
*/

typedef struct		s_parser
{
	int				nb_args;
	char			**args;
	t_obj			*obj;
	t_mtl			*mtl;
}					t_parser;

/*
** Functions
*/

void				init_parser(t_parser *parser, int ac, char **av);

int				    launch_parser(t_parser *parser,  int ac, char **av);
void				reader_obj(t_parser *parser);
void				reader_mtl(t_parser *parser);

int					check_raw_data(char *raw_data, t_parser_option *opt);

int					list_parser_to_obj(t_obj *obj, t_list_parser *list);

int					list_parser_to_mtl(t_mtl *mtl, t_list_parser *list);

void				parser_vt(t_obj *obj, char *raw_data);
void				parser_vn(t_obj *obj, char *raw_data);
void				parser_v(t_obj *obj, char *raw_data);
void				parser_f(t_obj *obj, char *raw_data);
void				parser_l(t_obj *obj, char *raw_data);
void				parser_mtl(t_obj *obj, char *raw_data);
void				parser_pass(t_obj *obj, char *raw_data);
void				parser_o(t_obj *obj, char *raw_data, int nb_entity);
void				parser_g(t_obj *obj, char *raw_data, int nb_entity);

void				parser_ka(t_mtl *mtl, char *raw_data);
void				parser_kd(t_mtl *mtl, char *raw_data);
void				parser_ks(t_mtl *mtl, char *raw_data);
void				parser_tf(t_mtl *mtl, char *raw_data);
void				parser_d(t_mtl *mtl, char *raw_data);
void				parser_s(t_mtl *mtl, char *raw_data);
void				parser_ni(t_mtl *mtl, char *raw_data);
void				parser_bump(t_mtl *mtl, char *raw_data);
void				parser_decal(t_mtl *mtl, char *raw_data);
void				parser_illum(t_mtl *mtl, char *raw_data);

#endif
