/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 11:30:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	main(int ac, char **av)
{
	t_parser	parser;

	launch_parser(&parser);
	(void)ac;
	(void)av;
	return (0);
}
