/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:16:53 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 19:49:44 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

double					last_double(char *raw_data)
{
	int					i;

	i = ft_strlen(raw_data) - 1;
	while (i && (raw_data[i] == ' ' || raw_data[i] == '\t'))
		i--;
	while (i && raw_data[i] != ' ' && raw_data[i] != '\t')
		i--;
	ft_printf("-- %s --\n", &raw_data[i]);
	return (ft_atof(&raw_data[i]));
}

static void				parser_k(t_texture_color *s, char *raw_data)
{
	ft_printf("parsing %s\n", raw_data);
	if (ft_strstr(raw_data, "spectral"))
	{
		parse_file(s->file, raw_data);
		s->factor = last_double(raw_data);
	}
	else
	{
		ft_strstr(raw_data, "xyz") ?
			parse_color(&(s->color), raw_data, 1) :
			parse_color(&(s->color), raw_data, 0);
	}
}

void					parser_ka(t_mtl *mtl, char *raw_data)
{
	if (mtl->ac)
		parsing_texture_option(&mtl->ac->option, raw_data, ID_KA);
	else
	{
		if (!(mtl->ac = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
        handle_error_parser("Error during memory allocation.");
		parser_k(mtl->ac, raw_data);    
	}
}

void				parser_kd(t_mtl *mtl, char *raw_data)
{
	if (mtl->dc)
		parsing_texture_option(&mtl->dc->option, raw_data, ID_KD);
	else
	{
		if (!(mtl->dc = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
        handle_error_parser("Error during memory allocation.");
		parser_k(mtl->dc, raw_data);
	}
}

void				parser_ks(t_mtl *mtl, char *raw_data)
{
	if (mtl->sc)
		parsing_texture_option(&mtl->sc->option, raw_data, ID_KS);
	else
	{
		if (!(mtl->sc = (t_texture_color *)ft_memalloc(sizeof(t_texture_color))))
        handle_error_parser("Error during memory allocation.");
		parser_k(mtl->sc, raw_data);    
	}
}
