/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:00:54 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/04/12 18:36:44 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "tools.h"

double		optional_value_double(char *str, double d)
{
	return (ft_strlen(str) ? ft_atof(str) : d);
}