/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:36:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/07 20:26:46 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

/*
Need function to use:	- new window -> OK 
						- clear window -> glClear
						- put pixel -> glDrawPixel but not optim maybe create a texture see link 1
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

						
1 - http://www.multigesture.net/articles/how-to-draw-pixels-to-a-texture-opengl/


TO DO:
		- put pixel (char-RGB) in a texture of the size of a screen
		- draw lines
		- load img (xpm free to use else code it or change imaeg type to xpm)
		- create image (load image and put it in a texture)
		- multi screen in windows
		- change screen (context)

		MATRIX:
		- create a lib to computate matrix
		- mutliply
		- add
		- pow

		MENU: 
		- create rect | circle | fonts -> for menus
		- create hit box for button and other things

add things when we things about it

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