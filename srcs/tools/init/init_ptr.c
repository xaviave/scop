/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:00:22 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 20:00:32 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

void		init_parser_obj_ptr(int (*f[7])(t_obj *, char *, int, int))
{
	f[0] = &parser_vt;
	f[1] = &parser_vn;
	f[2] = &parser_v;
	f[3] = &parser_f;
	f[4] = &parser_l;
	f[5] = &parser_mtl;
	f[6] = &parser_pass_obj;
}

void		init_parser_mtl_ptr(int (*f[13])(t_mtl *, char *, int))
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
	printf("Awesome shadding algorithme using machine learning number: %s\n",
		str);
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
