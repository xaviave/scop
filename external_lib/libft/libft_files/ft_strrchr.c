/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:25 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:58 by xamartin         ###   ########lyon.fr   */
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
