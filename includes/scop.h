/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:24 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 15:38:12 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** C library
*/

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

/*
** External Libraries
*/
 
# include "../libft/header/libft.h"
# include <SDL2/SDL.h>

/*
** Internal Libraries
*/

# include "cleaner.h"
# include "error.h"
# include "tools.h"

/*
** Defines
*/

# define PROG_NAME "Scop"

/*
** Structures
*/

typedef struct		s_obj
{
	char			**raw_obj;
}					t_obj;

typedef struct      s_prog
{
    int             exit_state;
    SDL_Window      *win;
    SDL_Event       ev;
}                   t_prog;

/*
** Functions
*/

#endif
