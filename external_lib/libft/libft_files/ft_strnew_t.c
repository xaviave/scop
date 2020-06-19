/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:24 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:24 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (!(s = ft_memalloc(size + 1)))
		return (NULL);
	return (s);
}
