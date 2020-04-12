/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_chunk_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:33:01 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:08:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int					get_gama(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_gama: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}

int					get_chrm(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_chrm: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}

int					get_srgb(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_srgb: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}

int					get_iccp(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_iccp: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}

int					get_trns(t_img *img, unsigned int *pass, unsigned int len)
{
	ft_printf("get_trns: pass = %d | len = %d\n", *pass, len);
	if (img)
		return (0);
	return (0);
}
