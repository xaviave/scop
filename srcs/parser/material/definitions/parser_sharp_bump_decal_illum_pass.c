/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sharp_bump_decal_illum_pass.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:17:58 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:28:11 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

int 				parser_bump(t_mtl *mtl, char *raw_data)
{
	int				i;
	
	if (!(mtl->bump = (t_bump *)ft_memalloc(sizeof(t_bump))))
	    return (0);
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->bump->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->bump->option, &mtl->bump->file,
		raw_data, ID_BUMP)))
	    return (0);
	if (!(parse_file(&mtl->bump->file, &raw_data[pass_texture_option(raw_data)])))
	    return (0);
	return (1);
}

int 				parser_decal(t_mtl *mtl, char *raw_data)
{
	int				i;
	if (!(mtl->decal = (t_decal *)ft_memalloc(sizeof(t_decal))))
	    return (0);
	i = pass_whitespace(5, raw_data);
	if (!(init_texture_option(&mtl->decal->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->decal->option, &mtl->decal->file,
		&raw_data[i], ID_DECAL)))
	    return (0);
	if (!(parse_file(&mtl->decal->file, &raw_data[pass_texture_option(raw_data)])))
	    return (0);
	return (1);
}

int 				parser_illum(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->shading = (t_shading *)ft_memalloc(sizeof(t_shading))))
	    return (0);
	mtl->shading->type = ft_atoi(&raw_data[5]);
	init_shading_ptr(mtl->shading->f);
	return (1);
}

int 				parser_sharp(t_mtl *mtl, char *raw_data)
{
	mtl->sharpness = ft_atof(&raw_data[pass_texture_option(raw_data)]);
	return (1);
}

int 				parser_disp(t_mtl *mtl, char *raw_data)
{
	int				i;
	
	if (!(mtl->disp = (t_disp *)ft_memalloc(sizeof(t_disp))))
	    return (0);
	i = pass_whitespace(4, raw_data);
	if (!(init_texture_option(&mtl->disp->option)))
	    return (0);
	if (!(parsing_texture_option(&mtl->disp->option, &mtl->disp->file,
		&raw_data[i], ID_DISP)))
	    return (0);
	if (!(parse_file(&mtl->disp->file, &raw_data[pass_texture_option(raw_data)])))
	    return (0);
	return (1);
}

int 				parser_pass_mtl(t_mtl *mtl, char *raw_data)
{
	ft_printf("This line is ignored | mtl id = %d | data = %s\n", mtl->id, raw_data);
	return (1);
}