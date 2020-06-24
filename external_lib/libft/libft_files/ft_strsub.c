/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:26 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:59 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*troncon;
	unsigned int	i;
	unsigned int	y;

	i = start;
	y = 0;
	if (s == NULL)
		return (NULL);
	if ((troncon = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < (start + len))
	{
		troncon[y] = s[i];
		i++;
		y++;
	}
	troncon[y] = '\0';
	return (troncon);
}
