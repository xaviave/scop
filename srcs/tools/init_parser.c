/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:44:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/28 20:43:56 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static int	last_char(char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (!nb_char(str, c))
		return (0);
	while (--i)
		if (str[i] == c)
			return (ft_strlen(str) - i - 1);
	return (i);
}

static char	*get_path(char *str)
{
	int		pos_delim;
	char	*path;

	pos_delim = ft_strlen(str) - last_char(str, '/');
	if (!pos_delim)
		return (ft_strdup("./"));
	path = ft_strndup(str, pos_delim);
	path[pos_delim] = '\0';
	return (path);
}

void	init_parser(t_parser *parser, int ac, char **av)
{
	int	i;

	parser->nb_args = ac - 1;
	parser->args = av;
	if (!(parser->obj = (t_obj *)malloc(sizeof(t_obj) * parser->nb_args)))
		handle_error_parser("Error during memory allocation.");
	if (!(parser->path = (char **)malloc(sizeof(char *) * parser->nb_args)))
		handle_error_parser("Error during memory allocation.");
	i = 0;
	while (++i < parser->nb_args + 1)
		parser->path[i] = get_path(av[i]);
}