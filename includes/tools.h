/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 17:11:38 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/*
** Defines
*/

# define True 1
# define False 0

/*
** Structures
*/

typedef struct		s_list_parser
{
    short           id; // id define the first type of objects
	char			*data;
	void			*next;
}					t_list_parser;

/*
** Functions
*/

void				add_list_parser(t_list_parser **list, char *raw_data);

void                init_obj(t_obj *obj);

int					pass_whitespace_float(int i,char *str);

float				optionnal_value_float(char *str, float d);

float				ft_atof(char *str);


#endif
