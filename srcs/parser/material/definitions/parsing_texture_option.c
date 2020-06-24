/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:48:38 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:13 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

static int				get_on_off(char *option_str)
{
	int					i;

	i = pass_whitespace(0, option_str);
	return (ft_strcmp(&option_str[i], "on") ? 1 : 0);
}

static int				get_value(char *option_str, int type)
{
	int					i;

	i = pass_whitespace(0, option_str);
	return (type ? ft_atof(&option_str[i]) : ft_atoi(&option_str[i]));
}

static void				get_double_tab(char *option_str, double *tab, int size)
{
	int					i;
	int					nb;

	nb = -1;
	i = pass_whitespace(0, option_str);
	while (++nb < size)
	{
		tab[nb] = ft_atof(&option_str[i]);
		i = pass_whitespace_str(0, option_str);
	}
}

/*
** define value for option by searching specific value
**| shitty way to avoid the norm error
*/

static void				define_value_by_option(t_texture_option *new,
	char *option, short t)
{
	if (ft_strchr(option, 'u'))
		new->blendu = get_on_off(&option[7]);
	else if (ft_strchr(option, 'v'))
		new->blendv = get_on_off(&option[7]);
	else if (ft_strchr(option, 'l'))
		new->clamp = get_on_off(&option[6]);
	else if (ft_strchr(option, 'c') && (t == ID_KA || t == ID_KD || t == ID_KS))
		new->cc = get_on_off(&option[3]);
	else if (ft_strchr(option, 'f') && t != ID_KA && t != ID_KD && t != ID_KS)
		new->imfchan = get_value(&option[8], 0);
	else if (ft_strchr(option, 'x'))
		new->texres = get_on_off(&option[3]);
	else if (ft_strchr(option, 'o'))
		get_double_tab(&option[2], new->o, 3);
	else if (ft_strchr(option, 's'))
		get_double_tab(&option[2], new->s, 3);
	else if (ft_strchr(option, 't'))
		get_double_tab(&option[2], new->t, 3);
	else if (ft_strstr(option, "bm") && t == ID_BUMP)
		new->bm = get_value(&option[3], 0);
	else if (ft_strchr(option, 'm'))
		get_double_tab(&option[2], new->mm, 2);
	else if (ft_strchr(option, 'b'))
		new->boost = get_value(&option[3], 1);
}

int						parsing_texture_option(t_texture_option *new,
	t_file *file, char *raw_data, char *path)
{
	int					i;
	char				*tmp;
	char				**option_tab;

	if (raw_data[0] != '-')
		return (1);
	if (!(tmp = ft_strsub(raw_data, 0, pass_texture_option(raw_data))))
		return (0);
	if (!(option_tab = ft_strsplit(tmp, '-')))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	i = -1;
	while (option_tab[++i])
		define_value_by_option(new, option_tab[i], new->type);
	i = -1;
	while (option_tab[++i])
		ft_strdel(&option_tab[i]);
	free(option_tab);
	option_tab = NULL;
	if (!(parse_file(file, &raw_data[pass_texture_option(raw_data)], path)))
		return (0);
	return (1);
}
