/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:48:07 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 18:56:04 by ltoussai         ###   ########lyon.fr   */
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
		printf("Spectral color type not supported, use white rgb color\n");
		parse_color(&(s->color), "0 0 0", 0);
	}
	else
	{
		ft_strstr(raw_data, "xyz") ?
			parse_color(&(s->color), raw_data, 1) :
			parse_color(&(s->color), raw_data, 0);
	}
}

int						parser_ka(t_mtl *mtl, char *raw_data, int group_id)
{
	int					i;

	if (mtl->ac)
	{
		mtl->ac->option.type = ID_KA;
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->ac->option, &mtl->ac->file,
			&raw_data[i], mtl->path)))
			return (0);
	}
	else
	{
		if (!(mtl->ac = (t_texture_color *)ft_memalloc(
			sizeof(t_texture_color))))
			return (0);
		mtl->ac->group_id = group_id;
		parser_color_file(mtl->ac, raw_data);
		if (!(init_texture_option(&mtl->ac->option)))
			return (0);
	}
	return (1);
}

int						parser_kd(t_mtl *mtl, char *raw_data, int group_id)
{
	int					i;

	if (mtl->dc)
	{
		mtl->dc->option.type = ID_KD;
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->dc->option, &mtl->dc->file,
			&raw_data[i], mtl->path)))
			return (0);
	}
	else
	{
		if (!(mtl->dc = (t_texture_color *)ft_memalloc(
			sizeof(t_texture_color))))
			return (0);
		mtl->dc->group_id = group_id;
		parser_color_file(mtl->dc, raw_data);
		if (!(init_texture_option(&mtl->dc->option)))
			return (0);
	}
	return (1);
}

int						parser_ks(t_mtl *mtl, char *raw_data, int group_id)
{
	int					i;

	if (mtl->sc)
	{
		mtl->sc->option.type = ID_KS;
		i = pass_whitespace(6, raw_data);
		if (!(parsing_texture_option(&mtl->sc->option, &mtl->sc->file,
			&raw_data[i], mtl->path)))
			return (0);
	}
	else
	{
		if (!(mtl->sc = (t_texture_color *)ft_memalloc(
			sizeof(t_texture_color))))
			return (0);
		mtl->sc->group_id = group_id;
		parser_color_file(mtl->sc, raw_data);
		if (!(init_texture_option(&mtl->sc->option)))
			return (0);
	}
	return (1);
}
