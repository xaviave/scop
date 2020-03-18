/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 15:57:59 by xamartin         ###   ########lyon.fr   */
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
	char			*data;
	void			*next;
}					t_list_parser;

/*
** Functions
*/

void				add_list_parser(t_list_parser **list, char *raw_data);

#endif
