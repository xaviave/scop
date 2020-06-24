/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:30:01 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:10:02 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../external_lib/libft/header/libft.h"
# include "parser_struct.h"

/*
** Functions
*/

void	handle_error_parser(char *message, t_addr **addr);
void	handle_error_render(char *message, t_addr **addr);

#endif
