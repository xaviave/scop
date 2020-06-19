/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:55:47 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:55:58 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

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

int			pass_whitespace(int i, char *str)
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
