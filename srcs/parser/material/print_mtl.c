/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:14:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/13 13:52:43 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_color(t_color *color)
{
	if (color)
		dprintf(1, "color: r = %f | g = %f | b = %f\n", color->r, color->g, color->b);
}

void	print_img(t_img *img)
{
	if (img)
		ft_printf("width = %.4u | length = %.4u \n", img->width, img->heigth);
}

void	print_file(t_file *file)
{
	if (file)
	{
		ft_printf("file: name = %s | path = %s\n", file->name, file->path);
		print_img(&file->img);
	}
}

void	print_double(char *str, double *tab, int len)
{
	int	i;

	i = -1;
	ft_printf("%s", str);
	while (++i < len)
		dprintf(1, "%f | ", tab[i]);
	ft_printf("\n");
}

void	print_texture_option(t_texture_option *opt)
{
	dprintf(1, "texture_option:\nblendu = %d | blendv = %d | cc = %d | clamp = %d | imfchan = %d\n", opt->blendu, opt->blendv, opt->cc, opt->clamp, opt->imfchan);
	print_double("mm = ", opt->mm, 2);
	print_double("o = ", opt->o, 3);
	print_double("s = ", opt->s, 3);
	print_double("t = ", opt->t, 3);
	dprintf(1, "texres = %f | boost = %f | bm = %d\n", opt->texres, opt->boost, opt->bm);
}

void	print_mtl(t_mtl *mtl)
{
	ft_printf("\n\n--------------------------------------------------\nMATERIAL: id = %d", mtl->id);
	ft_printf("\n\n--------------------------------------------------\nambient color: code Ka\n\n");
	if (mtl->ac)
	{
		print_color(&mtl->ac->color);
		print_file(&mtl->ac->file);
		dprintf(1, "factor = %f | group_id %d\n", mtl->ac->factor, mtl->ac->group_id);
		print_texture_option(&mtl->ac->option);
	}
	ft_printf("\n\n--------------------------------------------------\ndiffuse color: code Kd\n\n");
	if (mtl->dc)
	{
		print_color(&mtl->dc->color);
		print_file(&mtl->dc->file);
		dprintf(1, "factor = %f | group_id %d\n", mtl->dc->factor, mtl->dc->group_id);
		print_texture_option(&mtl->dc->option);
	}
	ft_printf("\n\n--------------------------------------------------\nspecular color: code Ks\n\n");
	if (mtl->sc)
	{
		print_color(&mtl->sc->color);
		print_file(&mtl->sc->file);
		dprintf(1, "factor = %f | group_id %d\n", mtl->sc->factor, mtl->sc->group_id);
		print_texture_option(&mtl->sc->option);
	}
	ft_printf("\n\n--------------------------------------------------\ntransmission filter: code Tf\n\n");
	if (mtl->tf)
	{
		dprintf(1, "group_id %d\n", mtl->tf->group_id);
		print_color(&mtl->tf->color);
		print_file(&mtl->tf->file);
	}
	ft_printf("\n--------------------------------------------------\ntransparent: code d\n\n");
	if (mtl->t)
	{
		dprintf(1, "halo = %d | factor = %f | group_id %d\n", mtl->t->halo, mtl->t->factor, mtl->t->group_id);
		print_file(&mtl->t->file);
		print_texture_option(&mtl->t->option);	
	}
	ft_printf("\n--------------------------------------------------\nspecular exponent: code Ns\n\n");
	if (mtl->se)
	{
		dprintf(1, "value = %f | group_id %d\n", mtl->se->value, mtl->se->group_id);
		print_file(&mtl->se->file);
		print_texture_option(&mtl->se->option);
	}
	ft_printf("\n--------------------------------------------------\nsharpness: code sharpness\n\n");
	if (mtl->sharpness)
		dprintf(1, "value = %f | group_id %d\n", mtl->sharpness->value, mtl->sharpness->group_id);
	if (mtl->od)
		dprintf(1, "value = %f | group_id %d\n", mtl->od->value, mtl->od->group_id);
	ft_printf("\n--------------------------------------------------\nbump: code bump\n\n");
	if (mtl->bump)
	{
		dprintf(1, "group_id %d\n", mtl->bump->group_id);
		print_file(&mtl->bump->file);
		print_texture_option(&mtl->bump->option);
	}
	ft_printf("\n--------------------------------------------------\ndisp: code disp\n\n");
	if (mtl->disp)
	{
		dprintf(1, "group_id %d\n", mtl->disp->group_id);
		print_file(&mtl->disp->file);
		print_texture_option(&mtl->disp->option);
	}
	ft_printf("\n--------------------------------------------------\ndecal: code decal\n\n");
	if (mtl->decal)
	{
		dprintf(1, "group_id %d\n", mtl->decal->group_id);
		print_file(&mtl->decal->file);
		print_texture_option(&mtl->decal->option);
	}
	ft_printf("\n--------------------------------------------------\nshading: code illum\n\n");
	if (mtl->shading)
		ft_printf("type = %d | group_id %d\t", mtl->shading->type, mtl->shading->group_id);
	if (mtl->nb_groups)
	{
		int i = -1;
		while (++i < mtl->nb_groups)
			ft_printf("%s\t", mtl->groups[i]);
		ft_printf("\n");
	}
}