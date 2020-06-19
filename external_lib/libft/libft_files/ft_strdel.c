/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:20 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:20 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = (NULL);
	}
}
