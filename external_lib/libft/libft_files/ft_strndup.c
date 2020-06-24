/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:56 by xamartin         ###   ########lyon.fr   */
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
