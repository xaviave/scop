/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/15 18:58:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/*
** TOOLS.H
*/

# include "parser_struct.h"
# include "render_struct.h"
# include "error.h"

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

typedef struct				s_list_parser
{
    short           		id; // id define the first type of objects
	char					*data;
	struct s_list_parser	*next;
}							t_list_parser;

/*
** Functions
*/

int							len_list_parser_id(t_list_parser *list);

void                		init_obj(t_obj *obj, t_parser_option *opt,
                                     int id, int nb_args, t_addr **addr);

void						init_mtl(t_mtl *mtl, int id,
	t_parser *parser, int nb_groups);

void						init_parser_obj_ptr(int (*f[7])(t_obj *, char *, int, int));
void						init_parser_mtl_ptr(int (*f[13])(t_mtl *, char *, int));
void						init_shading_ptr(void (*f[11])(char *));
void						init_file_ptr(int (*f[10])(t_file *));

void						init_parser_option(t_parser_option *opt, char *file,
	int index, short parsing_type);
int 						init_texture_option(t_texture_option *new);

void						init_parser(t_parser *parser, int ac, char **av);
void						init_parser_mtl(t_parser *parser);

int							init_gdata(t_gdata *gdata, t_parser *parser);

int							pass_whitespace(int i, char *str);
int							pass_whitespace_str(int i, char *str);
int							pass_texture_option(char *str);

int							list_parser_len(t_list_parser **list);
void						add_list_parser(t_list_parser **list, char *raw_data,
	t_parser_option *opt, t_addr **addr);

int							last_char(char *str, char c);
int							count_char(char *str, int c);
int					        nb_char(char *str, int c);

void						print_obj(t_obj *obj);

void						print_mtl(t_mtl *mtl);

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

#endif
