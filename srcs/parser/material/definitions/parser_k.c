/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:16:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:28:18 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

double					last_double(char *raw_data)
{
	int					i;

	i = ft_strlen(raw_data) - 1;
	while (i && (raw_data[i] == ' ' || raw_data[i] == '\t'))
		i--;
	while (i && raw_data[i] != ' ' && raw_data[i] != '\t')
		i--;
	return (ft_atof(&raw_data[i]));
}

void					parser_color_file(t_texture_color *s, char *raw_data)
{
	if (ft_strstr(raw_data, "spectral"))
	{
		ft_printf("Spectral color type not supported, use white rgb color\n");
		parse_color(&(s->color), "0 0 0", 0);
	}
	else
	{
		ft_strstr(raw_data, "xyz") ?
			parse_color(&(s->color), raw_data, 1) :
			parse_color(&(s->color), raw_data, 0);
	}
}

int					parser_ka(t_mtl *mtl, char *raw_data)
{
	int				i;

	if (mtl->ac)
	{
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->ac->option, &mtl->ac->file,
			&raw_data[i], ID_KA)))
		    return (0);
	}
	else
	{
		if (!(mtl->ac = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
		    return (0);
		parser_color_file(mtl->ac, raw_data);
		if (!(init_texture_option(&mtl->ac->option)))
		    return (0);
	}
	return (1);
}

int 				parser_kd(t_mtl *mtl, char *raw_data)
{
	int				i;

	if (mtl->dc)
	{
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->dc->option, &mtl->dc->file,
			&raw_data[i], ID_KD)))
		    return (0);
	}
	else
	{
		if (!(mtl->dc = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
		    return (0);
		parser_color_file(mtl->dc, raw_data);
		if (!(init_texture_option(&mtl->dc->option)))
		    return (0);
	}
	return (1);
}

int 				parser_ks(t_mtl *mtl, char *raw_data)
{
	int				i;

	if (mtl->sc)
	{
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->sc->option, &mtl->sc->file,
			&raw_data[i], ID_KS)))
		    return (0);
	}
	else
	{
		if (!(mtl->sc = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
		    return (0);
		parser_color_file(mtl->sc, raw_data);
		if (!(init_texture_option(&mtl->sc->option)))
		    return (0);
	}
    return (1);
}
