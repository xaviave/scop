/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:30:27 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tools.h"


void	init_t_prog(t_prog *p, t_parser *parser)
{
    p->obj = parser->obj;
    p->mtl = parser->mtl;
}

void	init_graphic_context(t_sdl *sdl)
{
    sdl->win = NULL;
    sdl->gl_context = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        handle_error_sdl("SDL could not initialize.");
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// ^^^^ Useless lines ?
	if (!(sdl->win = SDL_CreateWindow(PROG_NAME, SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED, W, H,
									SDL_WINDOW_OPENGL)))
		handle_error_sdl("Window could not be created.");
	if (!(sdl->gl_context = SDL_GL_CreateContext(sdl->win)))
		handle_error_sdl("GL Context could not be created.");
	glewExperimental = GL_TRUE; //          useless in this version ?
	if (glewInit())
		handle_error_sdl("Glew could not initialize.");
}
