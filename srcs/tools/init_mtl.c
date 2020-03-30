/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:07:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/30 18:55:27 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static void         init_mtl_ptr(t_mtl *mtl, t_parser_option *opt)
{
	if (!(mtl->ac = (t_ambiant_color *)ft_memalloc(
            sizeof(t_ambiant_color) * opt->len[ID_KA])))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->dc = (t_diffuse_color *)ft_memalloc(
            sizeof(t_diffuse_color) * opt->len[ID_KD])))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->sc = (t_specular_color *)ft_memalloc(
            sizeof(t_specular_color) * opt->len[ID_KS])))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->tf = (t_transmission_filter *)ft_memalloc(
            sizeof(t_transmission_filter) * opt->len[ID_TF])))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->t = (t_transparent *)ft_memalloc(
            sizeof(t_transparent) * opt->len[ID_D])))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->se = (t_specular_exponent *)ft_memalloc(
            sizeof(t_specular_exponent) * opt->len[ID_NS])))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(
            sizeof(t_sharpness) * opt->len[ID_SHARP])))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->od = (t_optical_density *)ft_memalloc(
            sizeof(t_optical_density) * opt->len[ID_NI])))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->bump = (t_bump *)ft_memalloc(
            sizeof(t_bump) * opt->len[ID_BUMP])))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->decal = (t_decal *)ft_memalloc(
            sizeof(t_decal) * opt->len[ID_DECAL])))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->s = (t_shading *)ft_memalloc(
            sizeof(t_shading) * opt->len[ID_ILLUM])))
        handle_error_parser("Error during memory allocation.");
}

void					init_mtl(t_mtl *mtl, t_parser_option *opt)
{
	ft_printf("1");
	ft_memset(mtl, 0, sizeof(t_mtl));
	ft_printf("1");
	mtl->id = -1;
	ft_printf("1");
	init_mtl_ptr(mtl, opt);
	ft_printf("1");
}