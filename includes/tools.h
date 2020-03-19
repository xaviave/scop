/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/19 22:34:31 by xavier_mart      ###   ########lyon.fr   */
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

#endif
