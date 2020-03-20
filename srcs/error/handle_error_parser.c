/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:11:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 21:34:02 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void handle_error_parser(char *message, ...)
{
	ft_printf("%s\n", message);
	ft_printf("must free everything lol");
	while (1)
		;
	exit(0);
}
