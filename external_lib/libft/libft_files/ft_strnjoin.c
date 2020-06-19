/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:24 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:24 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*new;

	if (!(s1 && s2))
		return (NULL);
	if (!(new = ft_memalloc((len + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strncat(new, s1, len);
	ft_strcat(new, s2);
	return (new);
}
