/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tf_d_s_ni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:15:13 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/04 21:07:56 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/scop.h"

void				parser_tf(t_mtl *mtl, char *raw_data)
{
	unsigned long	size;

	size = sizeof(t_transmission_filter);
	if (!(mtl->tf = (t_transmission_filter *)ft_memalloc(size)))
		handle_error_parser("Error during memory allocation.");
	parser_color_file((t_texture_color *)mtl->tf, raw_data);
	dprintf(1, "ue pourquoi pas %f", mtl->tf->color.r);
}

void				parser_d(t_mtl *mtl, char *raw_data)
{
	int				i;

	if (mtl->t)
	{
		i = pass_whitespace(5, raw_data);
		parsing_texture_option(&mtl->t->option, &mtl->t->file,
			&raw_data[i], ID_D);
	}
	else
	{
		if (!(mtl->t = (t_transparent *)ft_memalloc(sizeof(t_transparent))))
			handle_error_parser("Error during memory allocation.");
		i = 1;
		if (ft_strchr(raw_data, 'h'))
		{
			i = pass_whitespace_number(i, raw_data);
			mtl->t->factor = ft_atof(&raw_data[i]);
			mtl->t->halo = 1;
		}
		else
			mtl->t->factor = ft_atof(&raw_data[i]);
		init_texture_option(&mtl->t->option);
	}
}

void				parser_ns(t_mtl *mtl, char *raw_data)
{
	int				i;
	unsigned long	size;

	if (mtl->se)
	{
		i = pass_whitespace(6, raw_data);
		parsing_texture_option(&mtl->se->option, &mtl->se->file,
			&raw_data[i], ID_NS);
	}
	else
	{
		size = sizeof(t_specular_exponent);
		if (!(mtl->se = (t_specular_exponent *)ft_memalloc(size)))
        	handle_error_parser("Error during memory allocation.");
		mtl->se->value = ft_atof(&raw_data[pass_texture_option(raw_data)]);
		init_texture_option(&mtl->se->option);
	}
}

void				parser_ni(t_mtl *mtl, char *raw_data)
{
	mtl->od = ft_atof(&raw_data[pass_texture_option(raw_data)]);
}
