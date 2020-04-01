/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:45:59 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 01:06:27 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

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

void		init_parser_mtl_ptr(void (*f[12])(t_mtl *, char *))
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
	f[10] = &parser_illum;
	f[11] = &parser_pass_mtl;
}