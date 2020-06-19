/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sharp_bump_decal_illum_pass.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:48:25 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:00:02 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int					parser_bump(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;

	if (!(mtl->bump = (t_bump *)ft_memalloc(sizeof(t_bump))))
		return (0);
	mtl->bump->group_id = group_id;
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->bump->option)))
		return (0);
	mtl->bump->option.type = ID_BUMP;
	if (!(parsing_texture_option(&mtl->bump->option, &mtl->bump->file,
		&raw_data[i], mtl->path)))
		return (0);
	return (1);
}

int					parser_decal(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;

	if (!(mtl->decal = (t_decal *)ft_memalloc(sizeof(t_decal))))
		return (0);
	mtl->decal->group_id = group_id;
	i = pass_whitespace(5, raw_data);
	if (!(init_texture_option(&mtl->decal->option)))
		return (0);
	mtl->decal->option.type = ID_DECAL;
	if (!(parsing_texture_option(&mtl->decal->option, &mtl->decal->file,
		&raw_data[i], mtl->path)))
		return (0);
	return (1);
}

int					parser_illum(t_mtl *mtl, char *raw_data, int group_id)
{
	if (mtl->shading)
		return (1);
	if (!(mtl->shading = (t_shading *)ft_memalloc(sizeof(t_shading))))
		return (0);
	mtl->shading->group_id = group_id;
	mtl->shading->type = ft_atoi(&raw_data[5]);
	init_shading_ptr(mtl->shading->f);
	return (1);
}

int					parser_sharp(t_mtl *mtl, char *raw_data, int group_id)
{
	if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(sizeof(t_sharpness))))
		return (0);
	mtl->sharpness->group_id = group_id;
	mtl->sharpness->value = ft_atof(&raw_data[8]);
	return (1);
}

int					parser_disp(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;

	if (!(mtl->disp = (t_disp *)ft_memalloc(sizeof(t_disp))))
		return (0);
	mtl->disp->group_id = group_id;
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->disp->option)))
		return (0);
	mtl->disp->option.type = ID_DISP;
	if (!(parsing_texture_option(&mtl->disp->option, &mtl->disp->file,
		&raw_data[i], mtl->path)))
		return (0);
	return (1);
}
