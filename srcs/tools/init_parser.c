/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:44:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/21 10:46:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	init_parser(t_parser *parser, int ac, char **av)
{
	parser->nb_args = ac - 1;
	parser->args = av;
	if (!(parser->obj = (t_obj *)malloc(sizeof(t_obj) * parser->nb_args)))
		handle_error_parser("Error during memory allocation");
}