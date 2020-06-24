/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:04:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:04 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/*
** TOOLS.H
*/

# include "parser_struct.h"
# include "render_struct.h"
# include "./error.h"

/*
** Structures
*/

typedef struct				s_parser_option
{
	int						len[9];
	short					parsing_type;
	int						list_parser_len;
	int						index;
	char					*file;
	int						data_len;
}							t_parser_option;

typedef struct				s_status
{
	int						index;
	int						len_mtl;
	int						tab_len;
	int						ka;
	int						kd;
	int						ks;
	int						d;
	int						tr;
	int						tf;
	int						ns;
	int						ni;
	int						illum;
	int						map_[8];
}							t_status;

typedef struct				s_status_obj
{
	int						len_ver;
}							t_status_obj;

typedef struct				s_list_parser
{
	short					id;
	char					*data;
	struct s_list_parser	*next;
}							t_list_parser;

/*
** Functions
*/

int							is_num_or_float(char *str);

char						*change_chr(char *str, char c, char new_c);

int							len_tab(char **tab);
int							len_list_parser_id(t_list_parser *list);

void						init_obj(t_obj *obj, t_parser_option *opt,
		int id, t_parser *parser);

void						init_mtl(t_mtl *mtl, int id,
		t_parser *parser, int nb_groups);

void						init_parser_obj_ptr(
		int (*f[7])(t_obj *, char *, int, int));
void						init_parser_mtl_ptr(
		int (*f[13])(t_mtl *, char *, int));
void						init_shading_ptr(void (*f[11])(char *));
void						init_file_ptr(int (*f[10])(t_file *));

void						init_parser_option(t_parser_option *opt, char *file,
		int index, short parsing_type);
int							init_texture_option(t_texture_option *new);

void						init_parser(t_parser *parser, int ac, char **av);
void						init_parser_mtl(t_parser *parser);

int							init_gdata(t_gdata *gdata, t_parser *parser);

int							pass_whitespace(int i, char *str);
int							pass_whitespace_str(int i, char *str);
int							pass_texture_option(char *str);

int							list_parser_len(t_list_parser **list);
void						add_list_parser(t_list_parser **list,
		char *raw_data, t_parser_option *opt, t_addr **addr);

int							last_char(char *str, char c);
int							count_char(char *str, int c);
int							nb_char(char *str, int c);

int							count_group_mtl(t_list_parser *list);

double						optional_value_double(char *str, double d);

double						ft_atof(char *str);

char						*get_path(char *str);
char						*create_path(char *directory, char *file);

t_vertex					get_vertex(t_obj *obj, int id);
t_texture					get_texture(t_obj *obj, int id);
t_normal					get_normal(t_obj *obj, int id);
t_face						get_face(t_obj *obj, int id);
t_line						get_line(t_obj *obj, int id);

/*
** MATRIX
*/

/*
** srcs/tools/matrixes/basic_matrix4x4.c
*/

void						multiply_matrix4x4(t_matrix *result,
		t_matrix *m, t_matrix *multiply);
void						clear_matrix4x4(t_matrix *m);
void						translate_matrix4x4(t_matrix *m,
		float x, float y, float z);
void						ortho_matrix4x4(t_matrix *m, float tab[6]);

/*
** srcs/tools/matrixes/rotate_matrix4x4.c
*/

int							rotate_matrix4x4_x(t_matrix *rotate,
		t_matrix *m, float angle);
int							rotate_matrix4x4_y(t_matrix *rotate,
		t_matrix *m, float angle);
int							rotate_matrix4x4_z(t_matrix *rotate,
		t_matrix *m, float angle);

/*
** srcs/tools/matrixes/advanced_matrix4x4.c
*/

void						perspective_matrix4x4(t_matrix *m, float y_fov,
		float aspect, float n);
void						translate_in_place_matrix4x4(t_matrix *m,
		float x, float y, float z);
void						look_at_matrix4x4(t_matrix *m, float eye[3],
		float center[3], float up[3]);

/*
** srcs/tools/matrixes/tools_matrix4x4.c
*/

float						degree_to_radians(float angle);
float						*transform_matrix4x4_to_float(t_matrix *m);

/*
** srcs/tools/matrixes/vertex3.c
*/

void						vertex3_scale(float r[3],
		float const v[3], float const s);
float						vertex3_mul_inner(float const a[3],
		float const b[3]);
void						vertex3_mul_float(float r[3],
		float const a[3], float const b);
void						vertex3_sub(float r[3],
		float const a[3], float const b[3]);
void						vertex3_add(float r[3],
		float const a[3], float const b[3]);
void						vertex3_mul_cross(float r[3],
		float const a[3], float const b[3]);
void						vertex3_norm(float r[3], float const v[3]);

/*
** srcs/tools/matrixes/vertex3.c
*/

float						vertex4_mul_inner(float a[4], float b[4]);
void						vertex4_row_matrix4x4(float r[4],
		t_matrix *m, int i);

/*
** srcs/tools/matrixes/init_delete_matrix.c
*/

t_matrix					*new_matrix(int rows, int columns);
void						identity_matrix4x4(t_matrix *m);
t_matrix					*init_identity_matrix4x4(t_matrix *source);
void						*free_matrix(t_matrix *m);

/*
** http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-17-quaternions
*/

#endif
