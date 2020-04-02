/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sharp_bump_decal_illum_pass.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:17:58 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 19:04:13 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void				parser_bump(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->bump = (t_bump *)ft_memalloc(sizeof(t_bump))))
        handle_error_parser("Error during memory allocation.");
}

void				parser_decal(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->decal = (t_decal *)ft_memalloc(sizeof(t_decal))))
        handle_error_parser("Error during memory allocation.");
}

void				parser_illum(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->shading = (t_shading *)ft_memalloc(sizeof(t_shading))))
        handle_error_parser("Error during memory allocation.");

}

void				parser_sharp(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(sizeof(t_sharpness))))
        handle_error_parser("Error during memory allocation.");
	
}

void				parser_pass_mtl(t_mtl *mtl, char *raw_data)
{
	
}