/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/03 18:48:42 by xamartin         ###   ########lyon.fr   */
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
# define ID_ERR_OBJ 6
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
# define ID_BUMP 8
# define ID_DECAL 9
# define ID_DISP 10
# define ID_ILLUM 11
# define ID_ERR_MTL 12

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

typedef struct      		s_vertex
{
	double					x;
	double					y;
	double					z;
	double					w; // optionnal | default value 1.0
	int						group_id;
	int						object_id;
}							t_vertex;

/*
** t_texture defines the texture's coordinate.
** parsing: vt u[, v, w]
*/

typedef struct				s_texture
{
	double					u;
	double					v; //need to be between 0 and 1 | default 0
	double					w; //need to be between 0 and 1 | default 0
	int						group_id;
	int						object_id;
}							t_texture;

/*
** t_normal defines the vertex normals
** parsing: vn x y z
*/

typedef struct				s_normal
{
	double					x;
	double					y;
	double					z;
	int						group_id;
	int						object_id;
}							t_normal;

/*
** t_face defines a polygonal face element.
** Faces are defined using lists of vertex, texture and normal indices.
** parsing: f v1 v2[/vt2] v3[//vn3] v4[/vt4][/vn4] ...
*/

typedef struct				s_face
{
	int						group_id;
	int						object_id;
	int						nb_vertexes;
	int						*vertexes_id;
	short					has_texture;
	int						*textures_id;
	short					has_normal;
	int						*normals_id;
}							t_face;

/*
** t_line defines a polyline element.
** parsing: l v1 v2 v3
*/

typedef struct				s_line
{
	int						group_id;
	int						object_id;
	int						nb_vertexes;
	int						*vertexes_id;
	short					has_texture;
	int						*textures_id;
}							t_line;

/*
**
*/

typedef struct				s_group
{
	char					*name;
	short					smooth;
	int						object_id;
}							t_group;

/*
**
*/

typedef struct				s_object
{
	char					*name;
	short					smooth;
}							t_object;

/*
** t_obj have all the components of an obj.
*/

typedef struct				s_obj
{
	int						id;
	int						mtl_id;
	int						error;
	int						nb_default;
	char					*mtllib;

	char					**mtl;
	int						len_mtl;

	t_face					*faces;
	int						len_faces;

	t_group					*groups;
	int						len_groups;

	t_line					*lines;
	int						len_lines;

	t_normal				*normals;
	int						len_normals;

	t_object				*objects;
	int						len_objects;

	t_texture				*textures;
	int						len_textures;
	
	t_vertex				*vertexes;
	int						len_vertexes;
}							t_obj;

/*
** MATERIAL TEXTURE DEFINITION
** http://paulbourke.net/dataformats/mtl/
*/

typedef struct				s_color
{
	double					r; // between 0 and 1
	double					g; // equal to r if not given
	double					b; // equal to r if not given
}							t_color;

typedef struct				s_file
{
	char					*name;
	char					*path;
	int						type;
	void					*data;
}							t_file;

/*
** Define the texture option while call the referenced file
** All these args are found in Map_<struct name>
** All thoses values modify the texture map statements
*/

typedef struct				s_texture_option
{
	short					blendu; //  default on
	//  blendu turns texture blending in horizontal direction
	short					blendv; //  default on
	//  blendv turns texture blending in vertical direction
	short					cc; //  default on  
	//  Only for Ka | Kd | Ks
	//  turns on color correction for the texture
	short					clamp; //  default off
	//  texturea are restrict to 0-1 in the uvw range | refer to the doc
	short					imfchan; // default for bump is l and m for decal 
	//  Not for Ka | Kd | Ks
	//  choose between [r | g | m | l | z] to create a scalar or bump texture
	//  transparency - specular exponent - decal - displacement
	//  r -> red channel.
	//  g -> green channel.
	//  b -> blue channel.
	//  m -> matte channel.
	//  l -> luminance channel.
	//  z -> z-depth channel.
	double						*mm; // use to be like this [2];
	// modify the range over | scalar or color values may vary during rendering
	// mm[0] is the base, it adds values to texture. default 0 | change the brigther or dimmer
	// mm[1] is the gain, it expands the range of texture values and create contrast. default is 1
	double						*o; // use to be like this [3];
	// offset the position of the texture map on the surface | shift the position of the map origin. default [0, 0, 0]
	// o[0] is u horizontal direction
	// o[1] is v vertical direction | optionnal
	// o[2] is w depth for 3D texture and used for the amount of tesselation of the displacement | optionnal
	double						*s; // use to be like this [3];
	// scale the size of the texture pattern on the textured surface by expanding or shrinking the pattern. default [1, 1, 1]
	// s[0] is u horizontal direction
	// s[1] is v vertical direction | optionnal
	// s[2] is w depth for 3D texture and used for the amount of tesselation of the displacement | optionnal
	double						*t; // use to be like this [3];
	// turns on turbulence for texture. Adding turbulence to a texture along a specified direction adds variance to the original image
	// and allows a simple image to be repeated over a larger area without noticeable tiling effects. default [0, 0, 0]
	// t[0] is u horizontal direction
	// t[1] is v vertical direction | optionnal
	// t[2] is w depth for 3D texture and used for the amount of tesselation of the displacement | optionnal
	double					texres;
	// specifie the resolution of texture created when an image is used.
	// The default texture size is the largest power of two that does not exceed the original image size. Refere to doc
	double					boost; // always positive
	// increase the sharpness, or clarity, of mip-mapped texture files
	int						bm; // best between 0 and 1
	// -options but inly for bump
}							t_texture_option;

/*
** Class that define 3 states of a texture color
*/

typedef struct				s_texture_color
{
	t_color					color;
	t_file					file;
	double					factor;
	t_texture_option		option;
}							t_texture_color;

/*
** Transmission filter describes the specular reflectivity of a color
*/

typedef struct				s_transmission_filter
{
	// code: Tf
	t_color					color;
	t_file					file;
}							t_transmission_filter;

/*
** Transparent discribes the amout this material dissolves int the background
*/

typedef struct				s_transparent
{
	// code: d
	short					halo; // default 0 | formula =1.0 - (N*v)(1.0-factor)
	double					factor; // between 0 and 1 | 1 is opaque
	t_texture_option		option;
}							t_transparent;

/*
** Specular exponent describes the focus of the focus of the specular highlight
*/

typedef struct				s_specular_exponent
{
	// code: Ns
	double					value; // between 0 to 1000
	t_texture_option		option;
}							t_specular_exponent;

/*
** Sharpness describes the reflections from the local reflection map
*/

typedef struct				s_sharpness
{
	// code: sharpness
	double					value; // between 0 to 1000 | default 60
}							t_sharpness;

/*
** Optical density describes the optical density for the surface
*/

typedef struct				s_optical_density
{
	// code: Ni
	double					value; // between 0.001 to 10
}							t_optical_density;

/*
** MATERIAL TEXTURE MAP
*/

/*
** Specifies that a bump texture file or a bump procedural texture file is linked to the material.
*/

typedef struct				s_bump
{
	// code: bump
	// bm defines the bump multiplier
	// values stored with the texture or procedural texture file are multiplied by this value before they are applied to the surface.
	t_file					file;
	t_texture_option		option;
}							t_bump;

/*
** disp specifies that a scalar texture is used to deform the surface of an object, creating surface roughness.
*/

typedef struct				s_disp
{
	// code: disp
	t_file					file;
	t_texture_option		option;
}							t_disp;

/*
** decal replaces the material color with the texture color 
**
** During rendering, the Ka, Kd, and Ks values and the map_Ka, map_Kd, and 
** map_Ks values are blended according to the following formula:
**  vt == tv
** result_color=tex_color(tv)*decal(tv)+mtl_color*(1.0-decal(tv))
*/

typedef struct				s_decal
{
	// code: decal
	t_file					file;
	t_texture_option		option;
}							t_decal;

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

typedef struct				s_shading
{
	// code: illum
	int						type;
	void					(*f[11])(char *); // pointer to the shading algorithm
}							t_shading;

typedef struct				s_mtl
{
	int						id;
	char					*name; //no space else error

	//  No malloc here | using addr
	t_texture_color			*ac;
	//  code Ka
	//  Ambient color describes the ambiant refletivity of a color
	t_texture_color			*dc;
	//  code: Kd
	//  Diffuse color describes the refletivity of a color
	t_texture_color			*sc;
	//  code: Ks
	//  Specular color describes the specular reflectivity of a color
	t_transmission_filter	*tf;
	t_transparent			*t;

	t_specular_exponent		*se;
	t_sharpness				*sharpness;
	t_optical_density		*od;
	t_bump					*bump;
	t_disp					*disp;
	t_decal					*decal;
	t_shading				*shading;
}							t_mtl;

/*
** RENDER.H
*/

# define W 640
# define H 480

# define TRUE 1
# define FALSE 0

/*
** Render structure definition
*/

typedef struct      		s_prog
{
	int             		exit_state;
	SDL_Window      		*win;
	SDL_Event       		ev;
    SDL_GLContext   		gl_context;
}                   		t_prog;

/*
** Functions
*/

int         				launch_render(t_prog *p);


/*
** TOOLS.H
*/

// image file type
# define F_BMP
# define F_PNG
# define F_JPEG
# define F_JPG
// compiled procedural texture files
# define F_CXC
# define F_CXS
# define F_CXB
// mip-mapped texture files
# define F_MPC
# define F_MPS
# define F_MPB
// spectral Curve File | could not be parse
# define F_RFL

/*
** Structures
*/

typedef struct				s_parser_option
{
	int						len[7];
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

void                		init_obj(t_obj *obj, t_parser_option *opt, int id);

void						init_mtl(t_mtl *mtl, int id);

void						init_parser_obj_ptr(void (*f[7])(t_obj *, char *, int, int));
void						init_parser_mtl_ptr(void (*f[13])(t_mtl *, char *));
void						init_shading_ptr(void (*f[11])(char *));

void						init_parser_option(t_parser_option *opt, char *file,
	int index, short parsing_type);
void						init_texture_option(t_texture_option *new);

int							pass_whitespace(int i, char *str);
int							pass_whitespace_number(int i, char *str);
int							pass_texture_option(char *str);

int					        nb_char(char *str, int c);

void						print_obj(t_obj *obj);

void						print_mtl(t_mtl *mtl);

double						optional_value_double(char *str, double d);

double						ft_atof(char *str);

char						*get_path(char *str);
char						*create_path(char *directory, char *file);

int							last_char(char *str, char c);
int							count_char(char *str, int c);

/*
** PARSER.H
*/

/*
** Structures
*/

typedef struct				s_parser
{
	int						nb_args;
	char					**path;
	char					**args;
	t_obj					*obj;
	t_mtl					*mtl;
}							t_parser;

/*
** Functions
*/

void						init_parser(t_parser *parser, int ac, char **av);
void						init_parser_mtl(t_parser *parser);

int				    		launch_parser(t_parser *parser,  int ac, char **av);
void						reader_obj(t_parser *parser);
void						reader_mtl(t_parser *parser);

int							define_id_obj(char *raw_data, t_parser_option *opt);
int							define_id_mtl(char *raw_data, t_parser_option *opt);

int							check_raw_data(char *raw_data, t_parser_option *opt);

int							list_parser_to_obj(t_obj *obj, t_list_parser *list);

int							list_parser_to_mtl(t_mtl *mtl, t_list_parser *list);

void						parser_color_file(t_texture_color *s, char *raw_data);

void						parse_color(t_color *color, char *raw_data, int xyz);

void						parse_file(t_file *file, char *raw_data);

void						parser_vt(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_vn(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_v(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_f(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_l(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_mtl(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_pass_obj(t_obj *obj, char *raw_data, int o_id, int g_id);
void						parser_g(t_obj *obj, char *raw_data, int o_id);
void						parser_o(t_obj *obj, char *raw_data);

void						parser_ka(t_mtl *mtl, char *raw_data);
void						parser_kd(t_mtl *mtl, char *raw_data);
void						parser_ks(t_mtl *mtl, char *raw_data);
void						parser_tf(t_mtl *mtl, char *raw_data);
void						parser_d(t_mtl *mtl, char *raw_data);
void						parser_ns(t_mtl *mtl, char *raw_data);
void						parser_sharp(t_mtl *mtl, char *raw_data);
void						parser_ni(t_mtl *mtl, char *raw_data);
void						parser_bump(t_mtl *mtl, char *raw_data);
void						parser_disp(t_mtl *mtl, char *raw_data);
void						parser_decal(t_mtl *mtl, char *raw_data);
void						parser_illum(t_mtl *mtl, char *raw_data);
void						parser_pass_mtl(t_mtl *mtl, char *raw_data);
void						parsing_texture_option(t_texture_option *new, char *raw_data, short type);

#endif
