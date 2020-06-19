/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:10 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:10 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void		ft_int_swap(int *a, int *b)
{
	int		tmp;

	if (!(a && b))
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				*ft_bubble_sort(int *tab, int length)
{
	int		*fresh;
	int		i;
	int		j;

	if (!tab)
		return (NULL);
	i = 0;
	if (!(fresh = (int *)ft_memalloc(length * sizeof(int))))
		return (NULL);
	ft_memcpy(fresh, tab, length * sizeof(int));
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - 1 - i)
		{
			if (fresh[j] > fresh[j + 1])
				ft_int_swap(&(fresh[j]), &(fresh[j + 1]));
			j++;
		}
		i++;
	}
	return (fresh);
}
