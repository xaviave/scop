/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:26 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:26 by ltoussai         ###   ########lyon.fr   */
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
