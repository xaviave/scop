/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:45:59 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/24 22:00:58 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void		init_parser_ptr(void (*f[7])(t_obj *, char *))
{
	f[0] = &parser_vt;
	f[1] = &parser_vn;
	f[2] = &parser_v;
	f[3] = &parser_f;
	f[4] = &parser_l;
	f[5] = &parser_mtl;
	f[6] = &parser_pass;
}
