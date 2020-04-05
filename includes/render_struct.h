/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:16:09 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:21:25 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_STRUCT_H
# define SCOP_STRUCT_H

# include "scop.h"

# define GLEW_STATIC // useless ?
# include <GLEW/glew.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_opengl.h>
# include <OpenGl/gl.h>

typedef struct				s_sdl
{
	SDL_Event       		ev;
	SDL_Window      		*win;
    SDL_GLContext   		gl_context;
}							t_sdl;

typedef struct      		s_prog
{
	short					err;
	t_sdl					sdl;
	t_obj					*obj;
	t_mtl					*mtl;
}                   		t_prog;

#endif