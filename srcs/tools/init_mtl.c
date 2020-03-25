/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:07:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/26 00:00:05 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static void         reset_len(t_mtl *mtl)
{
    mtl->len_ac = 0;
    mtl->len_dc = 0;
    mtl->len_sc = 0;
    mtl->len_tf = 0;
    mtl->len_t = 0;
	mtl->len_se = 0;
	mtl->len_sharpness = 0;
    mtl->len_od = 0;
	mtl->len_bump = 0;
	mtl->len_decal = 0;
    mtl->len_s = 0;
}

static void         malloc_mtl_content(t_mtl *mtl)
{
	if (!(mtl->ac = (t_ambiant_color *)ft_memalloc(
            sizeof(t_ambiant_color) * mtl->len_ac + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->dc = (t_diffuse_color *)ft_memalloc(
            sizeof(t_diffuse_color) * mtl->len_dc + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->sc = (t_specular_color *)ft_memalloc(
            sizeof(t_specular_color) * mtl->len_sc + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->tf = (t_transmission_filter *)ft_memalloc(
            sizeof(t_transmission_filter) * mtl->len_tf + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->t = (t_transparent *)ft_memalloc(
            sizeof(t_transparent) * mtl->len_t + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->se = (t_specular_exponent *)ft_memalloc(
            sizeof(t_specular_exponent) * mtl->len_se + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->sharpness = (t_sharpness *)ft_memalloc(
            sizeof(t_sharpness) * mtl->len_sharpness + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->od = (t_optical_density *)ft_memalloc(
            sizeof(t_optical_density) * mtl->len_od + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->bump = (t_bump *)ft_memalloc(
            sizeof(t_bump) * mtl->len_bump + 1)))
        handle_error_parser("Error during memory allocation.");
    if (!(mtl->decal = (t_decal *)ft_memalloc(
            sizeof(t_decal) * mtl->len_decal + 1)))
        handle_error_parser("Error during memory allocation.");
	if (!(mtl->s = (t_shading *)ft_memalloc(
            sizeof(t_shading) * mtl->len_s + 1)))
        handle_error_parser("Error during memory allocation.");
}

void	            init_mtl_ptr(t_mtl *mtl, t_list_parser *list)
{
    t_list_parser   *tmp;

    tmp = list;
    while (tmp)
    {
        if (tmp->id == ID_KA)
            mtl->len_ac++;
        else if (tmp->id == ID_KD)
            mtl->len_dc++;
        else if (tmp->id == ID_KS)
            mtl->len_sc++;
        else if (tmp->id == ID_TF)
            mtl->len_tf++;
        else if (tmp->id == ID_D)
            mtl->len_t++;
		else if (tmp->id == ID_NS)
			mtl->len_se++;
		else if (tmp->id == ID_SHARP)
			mtl->len_sharpness++;
        else if (tmp->id == ID_NI)
            mtl->len_od++;
		else if (tmp->id == ID_BUMP)
			mtl->len_bump++;
		else if (tmp->id == ID_DECAL)
			mtl->len_decal++;
        else if (tmp->id == ID_ILLUM)
            mtl->len_s++;
        tmp = tmp->next;
    }
    malloc_mtl_content(mtl);
    reset_len(mtl);
}

void					init_mtl(t_mtl *mtl)
{
	ft_memset(mtl, 0, sizeof(t_mtl));
}