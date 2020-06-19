/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_t.c                                      :+:      :+:    :+:   */
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
	size_t	i;
	char	*sub;
	char	*cur;

	if (s)
	{
		if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		cur = (char *)s + start;
		i = 0;
		while (cur[i] && (i < len))
		{
			sub[i] = cur[i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
