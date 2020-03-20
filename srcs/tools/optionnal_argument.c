/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionnal_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:00:54 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 17:06:55 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

float		optionnal_value_float(char *str, float d)
{
	return (ft_strlen(str) ? ft_atof(str) : d);
}