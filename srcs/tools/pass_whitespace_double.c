/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 11:41:02 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 13:13:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

/*
** pass_whitespace_double pass all whitespaces and the first double
** return the index of the first whitespace found after the mouvement
*/

int			pass_whitespace_double(int i, char *str)
{
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i] && str[i] != '\t' && str[i] != ' ')
		i++;
	return (i);
}