/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_whitespace_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 11:41:02 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 17:04:34 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

/*
** pass_whitespace_number pass all whitespaces and the first number
** return the index of the first whitespace found after the movement
*/

int         pass_whitespace(int i, char *str)
{
    while (str[i] && (str[i] == '\t' || str[i] == ' '))
        i++;
    return (i);
}

int			pass_whitespace_number(int i, char *str)
{
    i = pass_whitespace(str)
	while (str[i] && str[i] != '\t' && str[i] != ' ')
		i++;
	return (i);
}