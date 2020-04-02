/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:10:50 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/04/02 23:34:01 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static double	get_decimal(char *str)
{
	int			i;
	int			len;
	double		res2;

	i = 0;
	len = 1;
	res2 = (double)ft_atoi(&str[++i]);
	while (str[++i] && str[i] != ' ' && str[i] != '\t')
		len++;
	while (len--)
		res2 /= 10;
	return (res2);
}

double			ft_atof(char *str)
{
	int			i;
	int			neg;
	double		res;

	i = 0;
	neg = 0;
	res = (double)ft_atoi(str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if ((res == 0 && str[i] == '-') || res < 0)
	{
		neg = -1;
		res = -res;
	}
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		return (res);
	res += get_decimal(&str[i]);
	return ((res >= 0.0 && neg == 0) ? res : -res);
}