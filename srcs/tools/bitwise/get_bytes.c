/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:20:01 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:38:34 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

unsigned int			get_4_bytes(unsigned char *data)
{
	unsigned char		o[4];

	ft_memcpy(o, data, 4);
	return ((unsigned int)(o[0] << 24) + (o[1] << 16) + (o[2] << 8) + o[3]);
}

unsigned int			get_4_bytes_pass(unsigned char *data,
	unsigned int *pass)
{
	unsigned int		bytes;

	bytes = get_4_bytes(&data[*pass]);
	*pass += 4;
	return (bytes);
}
