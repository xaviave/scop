/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sharp_bump_decal_illum_pass.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:17:58 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/03 00:03:26 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void				parser_bump(t_mtl *mtl, char *raw_data)
{
	ft_printf("Enter parser bump\n");
	if (!(mtl->bump = (t_bump *)ft_memalloc(sizeof(t_bump))))
        handle_error_parser("Error during memory allocation.");
	parse_file(&mtl->bump->file, &raw_data[pass_texture_option(raw_data)]);
	parsing_texture_option(&mtl->bump->option, raw_data, ID_BUMP);
}

void				parser_decal(t_mtl *mtl, char *raw_data)
{
	ft_printf("Enter parser decal\n");
	if (!(mtl->decal = (t_decal *)ft_memalloc(sizeof(t_decal))))
        handle_error_parser("Error during memory allocation.");
	parse_file(&mtl->decal->file, &raw_data[pass_texture_option(raw_data)]);
	parsing_texture_option(&mtl->decal->option, raw_data, ID_DECAL);
}

void				parser_illum(t_mtl *mtl, char *raw_data)
{
	ft_printf("Enter parser illum\n");
	if (!(mtl->shading = (t_shading *)ft_memalloc(sizeof(t_shading))))
        handle_error_parser("Error during memory allocation.");
	mtl->shading->type = ft_atoi(&raw_data[5]);
	ft_printf("ue");
	init_shading_ptr(mtl->shading->f);
}

void				parser_sharp(t_mtl *mtl, char *raw_data)
{
	ft_printf("Enter parser sharp\n");
	if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(sizeof(t_sharpness))))
        handle_error_parser("Error during memory allocation.");
	mtl->sharpness->value = ft_atof(&raw_data[pass_texture_option(raw_data)]);
	parsing_texture_option(&mtl->sharpness->option, raw_data, ID_SHARP);
}

void				parser_disp(t_mtl *mtl, char *raw_data)
{
	ft_printf("Enter parser disp\n");
	if (!(mtl->disp = (t_disp *)ft_memalloc(sizeof(t_disp))))
        handle_error_parser("Error during memory allocation.");
	parse_file(&mtl->disp->file, &raw_data[pass_texture_option(raw_data)]);
	parsing_texture_option(&mtl->disp->option, raw_data, ID_DISP);
}

void				parser_pass_mtl(t_mtl *mtl, char *raw_data)
{
	ft_printf("This line is ignored | mtl id = %d | data = %s\n", mtl->id, raw_data);
}