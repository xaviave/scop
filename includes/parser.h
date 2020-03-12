/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 13:17:19 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** Global Libraries
*/

# include "scop.h"

/*
** Structures
*/

typedef struct		s_parser
{
	int				nb_args;
	char			**args;
}					t_parser;


/*
** Functions
*/

void				launch_parser(t_parser *parser,  int ac, char **av);
void				reader(t_parser *parser);

#endif
