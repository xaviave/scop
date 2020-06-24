/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:17 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:48 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_pow(int n, int pow)
{
	long	result;
	size_t	i;

	i = 0;
	if (pow == 0)
		return (1);
	result = n;
	while ((int)i < pow - 1)
	{
		result *= n;
		i++;
	}
	return ((int)result);
}
