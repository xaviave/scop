/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/07 21:06:29 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** PARSER.H
*/

/*
** Internal Libraries
*/

# include "parser_struct.h"
# include "tools.h"
# include "cleaner.h"
# include "error.h"

/*
** Functions
*/

int				    		launch_parser(t_parser *parser,  int ac, char **av);
void						reader_obj(t_parser *parser);
void						reader_mtl(t_parser *parser);

int							define_id_obj(char *raw_data, t_parser_option *opt);
int							define_id_mtl(char *raw_data);

int							check_raw_data(char *raw_data, t_parser_option *opt);

int							list_parser_to_obj(t_obj *obj, t_list_parser *list,
        t_addr **addr);

int							list_parser_to_mtl(t_mtl *mtl, t_list_parser *list,
        t_addr **addr);

void						parser_color_file(t_texture_color *s, char *raw_data);

void						parse_color(t_color *color, char *raw_data, int xyz);

int 						parse_file(t_file *file, char *raw_data);

int 						parser_vt(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_vn(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_v(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_f(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_l(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_mtl(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_pass_obj(t_obj *obj, char *raw_data, int o_id, int g_id);
int 						parser_g(t_obj *obj, char *raw_data, int o_id);
int 						parser_o(t_obj *obj, char *raw_data);

int 						parser_ka(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_kd(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_ks(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_tf(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_d(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_ns(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_sharp(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_ni(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_bump(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_disp(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_decal(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_illum(t_mtl *mtl, char *raw_data, int group_id);
int 						parser_pass_mtl(t_mtl *mtl, char *raw_data, int group_id);
int 						parsing_texture_option(t_texture_option *new,
	t_file *file, char *raw_data, short type);

void						parser_bmp(t_file *file);
void						parser_png(t_file *file);
void						parser_jpeg(t_file *file);
void						parser_jpg(t_file *file);
void						parser_cxc(t_file *file);
void						parser_cxs(t_file *file);
void						parser_cxb(t_file *file);
void						parser_mpc(t_file *file);
void						parser_mps(t_file *file);
void						parser_mpb(t_file *file);

#endif
