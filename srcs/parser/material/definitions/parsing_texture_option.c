/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_option.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 12:18:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:34:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
** define value for option by searching specific value | shitty way to avoid the norm error
*/

static void				define_value_by_option(t_texture_option *new,
	char *option_tab, short type)
{
	if (ft_strchr(option_tab, 'u'))
		new->blendu = get_on_off(&option_tab[7]);
	else if (ft_strchr(option_tab, 'v'))
		new->blendv = get_on_off(&option_tab[7]);
	else if (ft_strchr(option_tab, 'l'))
		new->clamp = get_on_off(&option_tab[6]);
	else if (ft_strchr(option_tab, 'c') &&
		(type == ID_KA || type == ID_KD || type == ID_KS))
		new->cc = get_on_off(&option_tab[3]);
	else if (ft_strchr(option_tab, 'f') &&
		type != ID_KA & type != ID_KD && type != ID_KS)
		new->imfchan = get_value(&option_tab[8], 0);
	else if (ft_strchr(option_tab, 'x'))
		new->texres = get_on_off(&option_tab[3]);
	else if (ft_strchr(option_tab, 'o'))
		get_double_tab(&option_tab[2], new->o, 3);
	else if (ft_strchr(option_tab, 's'))
		get_double_tab(&option_tab[2], new->s, 3);
	else if (ft_strchr(option_tab, 't'))
		get_double_tab(&option_tab[2], new->t, 3);
	else if (ft_strstr(option_tab, "bm") && type == ID_BUMP)
		new->bm = get_value(&option_tab[3], 0);
	else if (ft_strchr(option_tab, 'm'))
		get_double_tab(&option_tab[2], new->mm, 2);
	else if (ft_strchr(option_tab, 'b'))
		new->boost = get_value(&option_tab[3], 1);
}

int 					parsing_texture_option(t_texture_option *new,
	t_file *file, char *raw_data, short type, char *path)
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
		define_value_by_option(new, option_tab[i], type);
	i = -1;
	while (option_tab[++i])
	    ft_strdel(&option_tab[i]);
	free(option_tab);
	option_tab = NULL;
	if (!(parse_file(file, &raw_data[pass_texture_option(raw_data)], path)))
	    return (0);
	return (1);
}