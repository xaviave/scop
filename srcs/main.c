/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:19:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/12 13:16:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/render.h"
#include <SDL2/SDL.h>

int	main(int ac, char **av)
{
	t_parser	parser;
	SDL_Window  *window;
	SDL_Event   e;
	int         quit;

//	launch_parser(&parser, ac, av);
    window = NULL;
    quit = 1;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        ft_printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
    else
    {
        if (!(window = SDL_CreateWindow("Scop", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                                  500, SDL_WINDOW_SHOWN)))
            ft_printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
        else
        {
            while (quit)
                while (SDL_PollEvent(&e))
                    if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN)
                        quit = 0;
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();


    return (0);
}
