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
# include "../includes/parser_struct.h"

/*
** Functions
*/

void        handle_error_parser(char *message, t_addr **addr);
void		handle_error_sdl(char *message, ...);

#endif
