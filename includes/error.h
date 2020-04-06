/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:30 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:36:20 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../libft/header/libft.h"

/*
** DEFINE for memory allocation and keep address.
** Exemple: M_OBJ_   = memory_t_obj*
**          M_CHAR_  = memory_char*
**          M_CHAR__ = memory_char**
**          put '_' after the define for the number of *
*/

# define M_OBJ_ 0
# define M_CHAR__ 1
# define M_L_PAR_ 2

typedef struct      s_addr
{
    void            *content_addr;
    int             content_type;
    struct s_addr   *next;
}                   t_addr;

/*
** Functions
*/

void        handle_error_parser(char *message, t_addr **addr);
void		handle_error_sdl(char *message, ...);
void        *addr_add(void *content, int type, t_addr **addr);

#endif
