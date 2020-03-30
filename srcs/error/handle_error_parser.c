/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:11:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 13:06:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void handle_error_parser(char *message, ...)
{
	ft_printf("%s\n", message);
	ft_printf("must free everything lol\n");
	// while (1)
	// 	;
	exit(0);
}