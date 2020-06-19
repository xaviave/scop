/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:23 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:23 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strndup(char *s1, int len)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2 = ft_strncpy(s2, s1, len);
	return (s2);
}
