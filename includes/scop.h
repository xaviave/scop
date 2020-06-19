/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:52:15 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 18:50:01 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** C library
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include "../external_lib/glad/include/glad/glad.h"
# include "../external_lib/libft/header/libft.h"

/*
** Defines
*/

# define PROG_NAME "Scop"

# define W 1080
# define H 720

# define TRUE 1
# define FALSE 0

/*
** OBJECT DEFINITION
** http://paulbourke.net/dataformats/obj/
*/

/*
** t_vertex defines a geometrical vertex.
** parsing: v x, y, z[, w]
*/

typedef struct				s_vertex
{
	double					x;
	double					y;
	double					z;
	double					w;
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
	double					v;
	double					w;
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

typedef struct				s_group
{
	char					*name;
	short					smooth;
	int						object_id;
}							t_group;

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
	int						nb_args;
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

	int						size_vertices;
	float					*vertices;
	int						size_indices;
	int						*indices;
	int						size_uv;
	float					*uv;
	float					min[3];
	float					max[3];
	float					axis[3];
}							t_obj;

/*
** MATERIAL TEXTURE DEFINITION
** http://paulbourke.net/dataformats/mtl/
*/

typedef struct				s_color
{
	double					r;
	double					g;
	double					b;
}							t_color;

typedef struct				s_img
{
	int						width;
	int						heigth;
	unsigned char			*data;
}							t_img;

typedef struct				s_file
{
	char					*name;
	char					*path;
	t_img					img;
}							t_file;

/*
** Define the texture option while call the referenced file
** All these args are found in Map_<struct name>
** All thoses values modify the texture map statements
*/

/*
**typedef struct				s_texture_option
**{
**	short					blendu; //  default on
**	//  blendu turns texture blending in horizontal direction
**	short					blendv; //  default on
**	//  blendv turns texture blending in vertical direction
**	short					cc; //  default on
**	//  Only for Ka | Kd | Ks
**	//  turns on color correction for the texture
**	short					clamp; //  default off
**	//  texturea are restrict to 0-1 in the uvw range | refer to the doc
**	short					imfchan; // default for bump is l and m for decal
**	//  Not for Ka | Kd | Ks
**	//  choose between [r | g | m | l | z] to create a scalar or bump texture
**	//  transparency - specular exponent - decal - displacement
**	//  r -> red channel.
**	//  g -> green channel.
**	//  b -> blue channel.
**	//  m -> matte channel.
**	//  l -> luminance channel.
**	//  z -> z-depth channel.
**	double					*mm; // use to be like this [2];
**	// modify the range over | scalar or color values may vary during rendering
**	// mm[0] is the base, it adds values to texture. default 0 | change the
**brigther or dimmer
**	// mm[1] is the gain, it expands the range of texture values and create
**contrast. default is 1
**	double					*o; // use to be like this [3];
**	// offset the position of the texture map on the surface | shift the
**position of the map origin. default [0, 0, 0]
**	// o[0] is u horizontal direction
**	// o[1] is v vertical direction | optional
**	// o[2] is w depth for 3D texture and used for the amount of tesselation of
**the displacement | optional
**	double					*s; // use to be like this [3];
**	// scale the size of the texture pattern on the textured surface by
**expanding or shrinking the pattern. default [1, 1, 1]
**	// s[0] is u horizontal direction
**	// s[1] is v vertical direction | optional
**	// s[2] is w depth for 3D texture and used for the amount of tesselation
**of the displacement | optional
**	double					*t; // use to be like this [3];
**	// turns on turbulence for texture. Adding turbulence to a texture along
**a specified direction adds variance to the original image
**	// and allows a simple image to be repeated over a larger area without
**noticeable tiling effects. default [0, 0, 0]
**	// t[0] is u horizontal direction
**	// t[1] is v vertical direction | optional
**	// t[2] is w depth for 3D texture and used for the amount of tesselation
**of the displacement | optional
**	double					texres;
**	// specifie the resolution of texture created when an image is used.
**	// The default texture size is the largest power of two that does not
**exceed the original image size. Refere to doc
**	double					boost; // always positive
**	// increase the sharpness, or clarity, of mip-mapped texture files
**	int						bm; // best between 0 and 1
**	// -options but inly for bump
**}							t_texture_option;
*/

typedef struct				s_texture_option
{
	short					blendu;
	short					blendv;
	short					cc;
	short					clamp;
	short					imfchan;
	double					*mm;
	double					*o;
	double					*s;
	double					*t;
	double					texres;
	double					boost;
	int						bm;
	short					type;
}							t_texture_option;

/*
** Class that define 3 states of a texture color
*/

typedef struct				s_texture_color
{
	int						group_id;
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
	int						group_id;
	t_color					color;
	t_file					file;
}							t_transmission_filter;

/*
** Transparent discribes the amout this material dissolves int the background
*/

typedef struct				s_transparent
{
	int						group_id;
	short					halo;
	double					factor;
	t_file					file;
	t_texture_option		option;
}							t_transparent;

/*
** Specular exponent describes the focus of the focus of the specular highlight
*/

typedef struct				s_specular_exponent
{
	int						group_id;
	double					value;
	t_file					file;
	t_texture_option		option;
}							t_specular_exponent;

/*
** MATERIAL TEXTURE MAP
*/

/*
** Sharpness describes the reflections from the local reflection map
*/

typedef struct				s_sharpness
{
	int						group_id;
	double					value;
}							t_sharpness;

/*
** Optical density describes the optical density for the surface
*/

typedef struct				s_optical_density
{
	int						group_id;
	double					value;
}							t_optical_density;

/*
** Specifies that a bump texture file or a bump procedural texture file is
**linked to the material.
*/

typedef struct				s_bump
{
	int						group_id;
	t_file					file;
	t_texture_option		option;
}							t_bump;

/*
** disp specifies that a scalar texture is used to deform the surface of an
**object, creating surface roughness.
*/

typedef struct				s_disp
{
	int						group_id;
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
	int						group_id;
	t_file					file;
	t_texture_option		option;
}							t_decal;

/*
**	algorithm:
**		0. Color on and Ambient off
**		1. Color on and Ambient on
**		2. Highlight on
**		3. Reflection on and Ray trace on
**		4. Transparency: Glass on, Reflection: Ray trace on
**		5. Reflection: Fresnel on and Ray trace on
**		6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
**		7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
**		8. Reflection on and Ray trace off
**		9. Transparency: Glass on, Reflection: Ray trace off
**		10. Casts shadows onto invisible surfaces
*/

typedef struct				s_shading
{
	int						group_id;
	int						type;
	void					(*f[11])(char *);
}							t_shading;

typedef struct				s_mtl
{
	int						id;
	int						nb_args;
	char					*path;
	int						nb_groups;
	char					**groups;

	t_texture_color			*ac;
	t_texture_color			*dc;
	t_texture_color			*sc;
	t_transmission_filter	*tf;
	t_transparent			*t;
	t_specular_exponent		*se;
	t_optical_density		*od;
	t_sharpness				*sharpness;
	t_bump					*bump;
	t_disp					*disp;
	t_decal					*decal;
	t_shading				*shading;
}							t_mtl;

#endif
