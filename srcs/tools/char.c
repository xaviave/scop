/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:13:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:29:58 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

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
	int len;

    if (!count_char(str, c))
        return (0);
	len = ft_strlen(str);
	i = len;
	while (--i)
		if (str[i] == c)
			return (len - i - 1);
	return (i);
}