/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionnal_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:00:54 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 20:35:36 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

float		optionnal_value_float(char *str, float d)
{
	return (ft_strlen(str) ? ft_atof(str) : d);
}