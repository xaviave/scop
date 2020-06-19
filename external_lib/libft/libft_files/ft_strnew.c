/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
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
	char *newstr;

	if ((newstr = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	else
		ft_bzero(newstr, size + 1);
	return (newstr);
}
