/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:45:26 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:46:10 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

int		is_num_or_float(char *str)
{
	int	i;
	int	point;

	i = str[0] == '-' ? 1 : 0;
	if (!ft_isdigit(str[i]) || str[ft_strlen(str) - 1] == '.')
		return (0);
	point = 0;
	while (str[i])
	{
		if (str[i] == '.')
			point++;
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (point > 1 ? FALSE : TRUE);
}

char	*change_chr(char *str, char c, char new_c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			str[i] = new_c;
	return (str);
}

int		len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

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
	int	len;

	if (!count_char(str, c))
		return (0);
	len = ft_strlen(str);
	i = len;
	while (--i)
		if (str[i] == c)
			return (len - i - 1);
	return (i);
}
