/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:45:10 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 16:59:54 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

/*
** pass_whitespace_float pass all whitespaces and the first float
** return the index of the first whitespace found after the mouvement
*/

int			pass_whitespace_float(int i, char *str)
{
	while (str[++i])
		if (ft_strisdigit(str[i]))
			break ;
	while (str[++i])
		if (str[i] == '\t' || str[i] == ' ')
			break ;
	return (i);
}