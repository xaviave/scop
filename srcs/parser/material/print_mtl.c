/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:14:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/03 00:08:57 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void	print_color(t_color *color)
{
	if (color)
		dprintf(1, "color: r = %f | g = %f | b = %f\n", color->r, color->g, color->b);
}

void	print_file(t_file *file)
{
	if (file)
		ft_printf("file: name = %s | path = %s | type = %d\n", file->name, file->path, file->type);
}

void	print_int(char *str, int *tab, int len)
{
	int	i;

	i = -1;
	ft_printf("%s", str);
	while (++i < len)
		ft_printf("%d | ", tab[i]);
	ft_printf("\n");
}

void	print_texture_option(t_texture_option *opt)
{
	dprintf(1, "texture_option:\nblendu = %d | blendv = %d | cc = %d | clamp = %d | imfchan = %d\n", opt->blendu, opt->blendv, opt->cc, opt->clamp, opt->imfchan);
	print_int("mm = ", opt->mm, 2);
	print_int("o = ", opt->o, 3);
	print_int("s = ", opt->s, 3);
	print_int("t = ", opt->t, 3);
	dprintf(1, "\ntexres = %f | boost = %f | bm = %d\n", opt->texres, opt->boost, opt->bm);
}

void	print_mtl(t_mtl *mtl)
{
	ft_printf("\n\n--------------------------------------------------\nMATERIAL: %s | id = %d", mtl->name, mtl->id);
	ft_printf("\n--------------------------------------------------\nambient color: code Ka\n");
	if (mtl->ac)
	{
		print_color(&mtl->ac->color);
		print_file(&mtl->ac->file);
		dprintf(1, "factor = %f\n", mtl->ac->factor);
		print_texture_option(&mtl->ac->option);
	}
	ft_printf("\n--------------------------------------------------\ndiffuse color: code Kd\n");
	if (mtl->dc)
	{
		print_color(&mtl->dc->color);
		print_file(&mtl->dc->file);
		dprintf(1, "factor = %f\n", mtl->dc->factor);
		print_texture_option(&mtl->dc->option);
	}
	ft_printf("\n--------------------------------------------------\nspecular color: code Ks\n");
	if (mtl->sc)
	{
		print_color(&mtl->sc->color);
		print_file(&mtl->sc->file);
		dprintf(1, "factor = %f\n", mtl->sc->factor);
		print_texture_option(&mtl->sc->option);
	}
	ft_printf("\n--------------------------------------------------\ntransmission filter: code Tf\n");
	if (mtl->tf)
	{
		print_color(&mtl->tf->color);
		print_file(&mtl->tf->file);
		print_texture_option(&mtl->tf->option);
	}
	ft_printf("\n--------------------------------------------------\ntransparent: code d\n");
	if (mtl->t)
		dprintf(1, "halo = %d | factor = %f\n", mtl->t->halo, mtl->t->factor);
	ft_printf("\n--------------------------------------------------\nspecular exponent: code Ns\n");
	if (mtl->se)
	{
		dprintf(1, "value = %f\n", mtl->se->value);
		print_texture_option(&mtl->se->option);
	}
	ft_printf("\n--------------------------------------------------\nsharpness: code sharpness\n");
	if (mtl->sharpness)
	{
		dprintf(1, "value = %f\n", mtl->sharpness->value);
		print_texture_option(&mtl->sharpness->option);
	}
	ft_printf("\n--------------------------------------------------\noptical density: code Ni\n");
	if (mtl->od)
	{
		dprintf(1, "value = %f\n", mtl->od->value);
		print_texture_option(&mtl->od->option);
	}
	ft_printf("\n--------------------------------------------------\nbump: code bump\n");
	if (mtl->bump)
	{
		print_file(&mtl->tf->file);
		print_texture_option(&mtl->bump->option);
	}
	ft_printf("\n--------------------------------------------------\ndisp: code disp\n");
	if (mtl->disp)
	{
		print_file(&mtl->disp->file);
		print_texture_option(&mtl->disp->option);
	}
	ft_printf("\n--------------------------------------------------\ndecal: code decal\n");
	if (mtl->decal)
	{
		print_file(&mtl->decal->file);
		print_texture_option(&mtl->decal->option);
	}
	ft_printf("\n--------------------------------------------------\nshading: code illum\n");
	if (mtl->shading)
	{
		ft_printf("type = %d\t", mtl->shading->type);
	}
}