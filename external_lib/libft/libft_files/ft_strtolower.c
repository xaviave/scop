/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:26 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:59 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strtolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
