/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:45:10 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/21 16:44:02 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

/*
** pass_whitespace_float pass all whitespaces and the first float
** return the index of the first whitespace found after the mouvement
*/

int			pass_whitespace_float(int i, char *str)
{
	// while (str[i] && ft_strisdigit(&str[i]))
	//	i++;
	while (str[++i])
		if (ft_strisdigit(&str[i]))
			break ;
	while (str[++i])
		if (str[i] == '\t' || str[i] == ' ')
			break ;
	return (i);
}