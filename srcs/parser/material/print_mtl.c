/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:14:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 19:53:20 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void	print_color(t_color *color)
{
	if (color)
		dprintf(1, "r = %f | g = %f | b = %f\n", color->r, color->g, color->b);
}

void	print_file(t_file *file)
{
	if (file)
		ft_printf("name = %s | path = %s | type = %d\n");
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
	dprintf(1, "blendu = %d | blendv = %d | cc = %d | clamp = %d | imfchan = %d\n", opt->blendu, opt->blendv, opt->cc, opt->clamp, opt->imfchan);
	print_int("mm = ", opt->mm, 2);
	print_int("o = ", opt->o, 3);
	print_int("s = ", opt->s, 3);
	print_int("t = ", opt->t, 3);
	dprintf(1, "\ntexres = %f | boost = %f\n", opt->texres, opt->boost);
}

void	print_mtl(t_mtl *mtl)
{
	ft_printf("\n\n--------------------------------------------------\nMATERIAL: %s | id = %d", mtl->name, mtl->id);
	ft_printf("\n--------------------------------------------------\nambient color:\n");
	if (mtl->ac)
	{
		print_color(&mtl->ac->color);
		print_file(mtl->ac->file);
		dprintf(1, "factor = %f\n", mtl->ac->factor);
		print_texture_option(&mtl->ac->option);
	}
	ft_printf("\n--------------------------------------------------\ndiffuse color:\n");
	if (mtl->dc)
	{
		print_color(&mtl->dc->color);
		print_file(mtl->dc->file);
		dprintf(1, "factor = %f\n", mtl->dc->factor);
		print_texture_option(&mtl->dc->option);
	}
	ft_printf("\n--------------------------------------------------\nspecular color:\n");
	if (mtl->sc)
	{
		print_color(&mtl->sc->color);
		print_file(mtl->sc->file);
		dprintf(1, "factor = %f\n", mtl->sc->factor);
		print_texture_option(&mtl->sc->option);
	}
	ft_printf("\n--------------------------------------------------\ntransmission filter:\n");
	if (mtl->tf)
	{
		print_color(&mtl->tf->color);
		print_file(mtl->tf->file);
		print_texture_option(&mtl->tf->option);
	}
	ft_printf("\n--------------------------------------------------\ntransparent:\n");
	if (mtl->t)
		dprintf(1, "halo = %d | factor = %f\n", mtl->t->halo, mtl->t->factor);
	ft_printf("\n--------------------------------------------------\nspecular exponent:\n");
	if (mtl->se)
	{
		dprintf(1, "value = %f\n", mtl->se->value);
		print_texture_option(&mtl->se->option);
	}
	ft_printf("\n--------------------------------------------------\nsharpnesst:\n");
	if (mtl->sharpness)
	{
		dprintf(1, "value = %f\n", mtl->sharpness->value);
		print_texture_option(&mtl->sharpness->option);
	}
	ft_printf("\n--------------------------------------------------\noptical density:\n");
	if (mtl->od)
	{
		dprintf(1, "value = %f\n", mtl->od->value);
		print_texture_option(&mtl->od->option);
	}
	ft_printf("\n--------------------------------------------------\nbump:\n");
	if (mtl->bump)
	{
		dprintf(1, "bm = %d\n", mtl->bump->bm);
		print_file(mtl->tf->file);
		print_texture_option(&mtl->bump->option);
	}
	ft_printf("\n--------------------------------------------------\ndisp:\n");
	if (mtl->disp)
	{
		print_file(mtl->disp->file);
		print_texture_option(&mtl->disp->option);
	}
	ft_printf("\n--------------------------------------------------\ndecal:\n");
	if (mtl->decal)
	{
		print_color(&mtl->decal->color);
		print_file(mtl->decal->file);
		print_texture_option(&mtl->decal->option);
	}
	ft_printf("\n--------------------------------------------------\nshading:\n");
	if (mtl->shading)
	{
		ft_printf("type = %d\t", mtl->shading->type);
		print_color(&mtl->shading->color);
	}
}