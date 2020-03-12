/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 11:24:35 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** Structures
*/

typedef struct		s_parser
{
	char			*name;
}					t_parser;


/*
** Functions
*/

void				launch_parser(t_parser *parser);

#endif
