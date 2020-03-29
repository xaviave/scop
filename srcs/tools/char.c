/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:13:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/29 16:17:04 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

int		count_char(char *str, int c)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (str[++i])
		if (str[i] == c)
			nb++;
	return (nb);
}

int		last_char(char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (!count_char(str, c))
		return (0);
	while (--i)
		if (str[i] == c)
			return (ft_strlen(str) - i - 1);
	return (i);
}