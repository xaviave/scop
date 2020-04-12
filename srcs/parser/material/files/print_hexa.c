/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:00:51 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:34:02 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				print_hexa(unsigned char *data, unsigned int len)
{
	unsigned int	width;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	width = 16;
 	ft_printf("\n---------------------------------\nSize: %d\n\n", len);
	while (++i < len)
	{
		j = -1;
		while (++j < width)
		{
			if (i + j < len)
				ft_printf("%02x ", data[j]);
		}
		data += width;
		i += j;
		ft_printf("\n");
	}
}