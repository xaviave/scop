/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:35 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 14:19:24 by xavier_mart      ###   ########lyon.fr   */
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
	t_obj			*obj;
}					t_parser;


/*
** Functions
*/

int				    launch_parser(t_parser *parser,  int ac, char **av);
void				reader(t_parser *parser);

void				parser_vt(t_obj *obj, char *raw_data);
void				parser_vn(t_obj *obj, char *raw_data);
void				parser_vp(t_obj *obj, char *raw_data);
void				parser_v(t_obj *obj, char *raw_data);
void				parser_f(t_obj *obj, char *raw_data);
void				parser_l(t_obj *obj, char *raw_data);
void				parser_pass(t_obj *obj, char *raw_data);

#endif
