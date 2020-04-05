/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:45:59 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:49:14 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

void		init_parser_obj_ptr(void (*f[7])(t_obj *, char *, int, int))
{
	f[0] = &parser_vt;
	f[1] = &parser_vn;
	f[2] = &parser_v;
	f[3] = &parser_f;
	f[4] = &parser_l;
	f[5] = &parser_mtl;
	f[6] = &parser_pass_obj;
}

void		init_parser_mtl_ptr(void (*f[13])(t_mtl *, char *))
{
	f[0] = &parser_ka;
	f[1] = &parser_kd;
	f[2] = &parser_ks;
	f[3] = &parser_tf;
	f[4] = &parser_d;
	f[5] = &parser_ns;
	f[6] = &parser_sharp;
	f[7] = &parser_ni;
	f[8] = &parser_bump;
	f[9] = &parser_decal;
	f[10] = &parser_disp;
	f[11] = &parser_illum;
	f[12] = &parser_pass_mtl;
}

void		pass_lol(char *str)
{
	ft_printf("Awesome shadding algorithme using machine learning number: %s\n", str);
}

void		init_shading_ptr(void (*f[11])(char *))
{
	f[0] = &pass_lol;
	f[1] = &pass_lol;
	f[2] = &pass_lol;
	f[3] = &pass_lol;
	f[4] = &pass_lol;
	f[5] = &pass_lol;
	f[6] = &pass_lol;
	f[7] = &pass_lol;
	f[8] = &pass_lol;
	f[9] = &pass_lol;
	f[10] = &pass_lol;
}

void pass_loli(t_file *file)
{
	if (file)
		ft_printf("Yo come on if you are here it s because you need img data lol -> code it");
}

void		init_file_ptr(void (*f[10])(t_file *))
{
	f[0] = &pass_loli;
	f[1] = &pass_loli;
	f[2] = &pass_loli;
	f[3] = &pass_loli;
	f[4] = &pass_loli;
	f[5] = &pass_loli;
	f[6] = &pass_loli;
	f[7] = &pass_loli;
	f[8] = &pass_loli;
	f[9] = &pass_loli;
// 	f[0] = &parser_bmp;
// 	f[1] = &parser_png;
// 	f[2] = &parser_jpeg;
// 	f[3] = &parser_jpg;
// 	f[4] = &parser_cxc;
// 	f[5] = &parser_cxs;
// 	f[6] = &parser_cxb;
// 	f[7] = &parser_mpc;
// 	f[8] = &parser_mps;
// 	f[9] = &parser_mpb;
}
