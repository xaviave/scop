/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:25 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:25 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	value;
	char	*start;
	char	*end;

	value = (char)c;
	start = (char *)s;
	end = (char *)s;
	while (*end)
		end++;
	if (c == '\0')
		return (end);
	end--;
	while (end >= start)
	{
		if (*end == c)
			return (end);
		end--;
	}
	return (NULL);
}
