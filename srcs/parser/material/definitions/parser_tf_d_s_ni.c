/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tf_d_s_ni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:15:13 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/09 00:34:00 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int 				parser_tf(t_mtl *mtl, char *raw_data, int group_id)
{
	unsigned long	size;

	size = sizeof(t_transmission_filter);
	if (!(mtl->tf = (t_transmission_filter *)ft_memalloc(size)))
	    return (0);
	mtl->tf->group_id = group_id;
	parser_color_file((t_texture_color *)mtl->tf, raw_data);
	dprintf(1, "ue pourquoi pas %f", mtl->tf->color.r);
	return (1);
}

int 				parser_d(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;

	if (mtl->t)
	{
		i = pass_whitespace(5, raw_data);
		if (!(parsing_texture_option(&mtl->t->option, &mtl->t->file,
			&raw_data[i], ID_D)))
		    return (0);
	}
	else
	{
		if (!(mtl->t = (t_transparent *)ft_memalloc(sizeof(t_transparent))))
		    return (0);
		mtl->t->group_id = group_id;
		if (ft_strchr(raw_data, 'h'))
		{
			i = pass_whitespace_number(1, raw_data);
			mtl->t->factor = ft_atof(&raw_data[i]);
			mtl->t->halo = 1;
		}
		else
			mtl->t->factor = ft_atof(&raw_data[1]);
		if (!(init_texture_option(&mtl->t->option)))
		    return (0);
	}
	return (1);
}

int 				parser_ns(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;
	unsigned long	size;

	if (mtl->se)
	{
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->se->option, &mtl->se->file,
			&raw_data[i], ID_NS)))
		    return (0);
	}
	else
	{
		size = sizeof(t_specular_exponent);
		if (!(mtl->se = (t_specular_exponent *)ft_memalloc(size)))
		    return (0);
		mtl->se->group_id = group_id;
		mtl->se->value = ft_atof(&raw_data[pass_texture_option(raw_data)]);
		if (!(init_texture_option(&mtl->se->option)))
		    return (0);
	}
    return (1);
}

int 				parser_ni(t_mtl *mtl, char *raw_data, int group_id)
{
	unsigned long	size;
	
	size = sizeof(t_optical_density);
	if (!(mtl->od = (t_optical_density *)ft_memalloc(size)))
	    return (0);
	if (mtl->disp)
	    mtl->disp->group_id = group_id;
	mtl->od->value = ft_atof(&raw_data[2]);
	return (1);
}
