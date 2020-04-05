/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:36:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 16:35:21 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

/*
Need function to use:	- new window -> OK 
						- clear window
						- put pixel
						- new image
						- get data addr
						- put image to window
						- get color value
						- loop / loop_hook / expose_hook / key_hook / mous_hook
						- auto replay for hook
						- put string
						- xpm to image
						- destroy image
						- swap buffer -> flushGLContext
						- change context ->  selectGLContext

*/

static void	graphic_loop(t_prog *p)
{
    while (p->err)
    {
        SDL_WaitEvent(&p->sdl.ev);
        if (p->sdl.ev.type == SDL_QUIT ||
            (p->sdl.ev.type == SDL_KEYDOWN && p->sdl.ev.key.keysym.sym == SDLK_ESCAPE))
            break;
       SDL_GL_SwapWindow(p->sdl.win);
//      ^^^  Make the window peter un cable, check if it's good idea when we'll fill the screen.
    }
    SDL_DestroyWindow(p->sdl.win);
    SDL_GL_DeleteContext(p->sdl.gl_context);
    SDL_Quit();
}

int         launch_render(t_prog *p, t_parser *parser)
{
    init_t_prog(p, parser);
	init_graphic_context(&p->sdl);
        graphic_loop(p);
	return (1);
}