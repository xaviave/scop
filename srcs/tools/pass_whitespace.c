/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 11:41:02 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/26 18:13:46 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "tools.h"

/*
** pass_whitespace_double pass all whitespaces and the first double
** return the index of the first whitespace found after the movement
*/

int			pass_whitespace_str(int i, char *str)
{
    i = pass_whitespace(i, str);
	while (str[i] && str[i] != '\t' && str[i] != ' ')
		i++;
	return (i);
}

int         pass_whitespace(int i, char *str)
{
    while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == 13))
        i++;
    return (i);
}

int			pass_texture_option(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i && str[i] != ' ' && str[i] != '\t')
		i--;
	return (i);
}