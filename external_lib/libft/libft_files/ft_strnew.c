/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:57 by xamartin         ###   ########lyon.fr   */
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
