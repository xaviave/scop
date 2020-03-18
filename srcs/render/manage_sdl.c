#include "../../includes/render.h"

static int  sdl_loop(t_prog *p)
{
    while (True)
    {
        SDL_WaitEvent(&p->ev);
        if (p->ev.type == SDL_QUIT ||
            (p->ev.type == SDL_KEYDOWN && p->ev.key.keysym.sym == SDLK_ESCAPE))
            break;
    }
    SDL_DestroyWindow(p->win);
    return (p->exit_state);
}

static int  init_sdl(t_prog *p)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        p->exit_state = handle_error_sdl("SDL could not initialize.");
    else
    {
        if (!(p->win = SDL_CreateWindow(PROG_NAME, SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, W, H,
                                        SDL_WINDOW_SHOWN)))
            p->exit_state = handle_error_sdl("Window could not be created.");
    }
    return (p->exit_state);
}

int         manage_sdl(t_prog *p)
{
    if (init_sdl(p) != -1)
        sdl_loop(p);
    SDL_Quit();
    return (p->exit_state);
}