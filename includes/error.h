/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:30:01 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 13:30:06 by ltoussai         ###   ########lyon.fr   */
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
