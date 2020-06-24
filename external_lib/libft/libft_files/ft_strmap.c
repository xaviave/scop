/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:22 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:54 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	if (s)
	{
		if (!(new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = f((char)(s[i]));
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
