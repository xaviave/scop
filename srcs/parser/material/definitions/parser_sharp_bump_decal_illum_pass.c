/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sharp_bump_decal_illum_pass.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:17:58 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:34:35 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int 				parser_bump(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;
	
	if (!(mtl->bump = (t_bump *)ft_memalloc(sizeof(t_bump))))
	    return (0);
	mtl->bump->group_id = group_id;
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->bump->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->bump->option, &mtl->bump->file,
		&raw_data[i], ID_BUMP, mtl->path)))
	    return (0);
	return (1);
}

int 				parser_decal(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;
	if (!(mtl->decal = (t_decal *)ft_memalloc(sizeof(t_decal))))
	    return (0);
	mtl->decal->group_id = group_id;
	i = pass_whitespace(5, raw_data);
	if (!(init_texture_option(&mtl->decal->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->decal->option, &mtl->decal->file,
		&raw_data[i], ID_DECAL, mtl->path)))
	    return (0);
	return (1);
}

int 				parser_illum(t_mtl *mtl, char *raw_data, int group_id)
{
	if (!(mtl->shading = (t_shading *)ft_memalloc(sizeof(t_shading))))
	    return (0);
	mtl->shading->group_id = group_id;
	mtl->shading->type = ft_atoi(&raw_data[5]);
	init_shading_ptr(mtl->shading->f);
	return (1);
}

int 				parser_sharp(t_mtl *mtl, char *raw_data, int group_id)
{
	if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(sizeof(t_sharpness))))
	    return (0);
	mtl->sharpness->group_id = group_id;
	mtl->sharpness->value = ft_atof(&raw_data[8]);
	return (1);
}

int 				parser_disp(t_mtl *mtl, char *raw_data, int group_id)
{
	int				i;
	
	if (!(mtl->disp = (t_disp *)ft_memalloc(sizeof(t_disp))))
	    return (0);
	mtl->disp->group_id = group_id;
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->disp->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->disp->option, &mtl->disp->file,
		&raw_data[i], ID_DISP, mtl->path)))
	    return (0);
	return (1);
}

int 				parser_pass_mtl(t_mtl *mtl, char *raw_data, int group_id)
{
	if (raw_data[0] != '#' && ft_strstr(raw_data, "newmtl"))
		mtl->groups[group_id] = ft_strtrim(&raw_data[6]);
	else
		ft_printf("This line is ignored | mtl id = %d | data = %s\n", mtl->id, raw_data);
	return (1);
}