/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:36:23 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/13 16:01:04 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
Need function to use:	- new window -> OK 
						- put pixel -> glDrawPixel but not optim maybe create a texture see link 1
						- new image -> texture glTexImage2D
						- get data addr
						- put image to window
						- get color value
						- loop / loop_hook / expose_hook / key_hook / mouse_hook
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

function TO DO:
	- poll event
	- block fps to 30
	- normalizer for every coordonate (min -1.0f max 1.0)

*/

void		clear_buffer()
{
	// put the coor white in GL_COLOR_BUFFER_BIT
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// apply the GL_COLOR_BUFFER_BIT n the buffer
	glClear(GL_COLOR_BUFFER_BIT);
}

void		setup_texture(unsigned int screen_data[H][W][3])
{
	// https://open.gl/textures

	ft_bzero(screen_data, sizeof(&screen_data));
	// https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml
	glTexImage2D(GL_TEXTURE_2D, 0, 3, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screen_data);
	// https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // https://www.flipcode.com/archives/Advanced_OpenGL_Texture_Mapping.shtml
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); 
    // Enable textures
    glEnable(GL_TEXTURE_2D);
}

void		update_texture(unsigned int screen_data[H][W][3], double color)
{
	int				x;
	int				y;
	unsigned int	display_width;
	unsigned int	display_height;

	display_width = 64;
	display_height = 32;
	
	y = -1;
    while (++y < 32)
	{
		x = -1;
        while (++x < 64)
		{
            if(color > 0.5)
            {
				screen_data[y][x][0] = 0;
				screen_data[y][x][1] = 0;
				screen_data[y][x][2] = 0;
			}
            else
			{
                screen_data[y][x][0] = 255;
				screen_data[y][x][1] = 255;
				screen_data[y][x][2] = 255;
			}
		}
	}

    glTexSubImage2D(GL_TEXTURE_2D, 0 ,0, 0, W, H, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screen_data);
 
    glBegin( GL_QUADS );
        glTexCoord2d(0.0, 0.0);		glVertex2d(0.0,			  0.0);
        glTexCoord2d(1.0, 0.0); 	glVertex2d(display_width, 0.0);
        glTexCoord2d(1.0, 1.0); 	glVertex2d(display_width, display_height);
        glTexCoord2d(0.0, 1.0); 	glVertex2d(0.0,			  display_height);
    glEnd();
}

static void	graphic_loop(t_prog *p)
{
	unsigned int	screen_data[H][W][3];
	int				color;
	double 			tmp;

	color = 0;
	setup_texture(screen_data);
    while (p->err)
    {
        SDL_WaitEvent(&p->sdl.ev);
        if (p->sdl.ev.type == SDL_QUIT ||
            (p->sdl.ev.type == SDL_KEYDOWN &&
			p->sdl.ev.key.keysym.sym == SDLK_ESCAPE))
            break;
		tmp = (++color % 255) / 255.0;
		update_texture(screen_data, tmp);
		SDL_GL_SwapWindow(p->sdl.win); // need to find the glutswapbuffers equivalent
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