#include "../../includes/render.h"

static int  init_t_prog(t_prog *p)
{
    p->exit_state = 0;
    p->win = NULL;
    p->gl_context = NULL;
    return (p->exit_state);
}

static int  graphic_loop(t_prog *p)
{
    while (True)
    {
        SDL_WaitEvent(&p->ev);
        if (p->ev.type == SDL_QUIT ||
            (p->ev.type == SDL_KEYDOWN && p->ev.key.keysym.sym == SDLK_ESCAPE))
            break;
//        SDL_GL_SwapWindow(p->win);
//      ^^^  Make the window peter un cable, check if it's good idea when we'll fill the screen.
    }
    SDL_DestroyWindow(p->win);
    SDL_GL_DeleteContext(p->gl_context);
    SDL_Quit();
    return (p->exit_state);
}

static int  init_graphic_context(t_prog *p)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        p->exit_state = handle_error_sdl("SDL could not initialize.");
    else
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        // ^^^^ Useless lines ?
        if (!(p->win = SDL_CreateWindow(PROG_NAME, SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, W, H,
                                        SDL_WINDOW_OPENGL)))
            p->exit_state = handle_error_sdl("Window could not be created.");
        else
        {
            if (!(p->gl_context = SDL_GL_CreateContext(p->win)))
                p->exit_state = handle_error_sdl("GL Context could not be created.");
            glewExperimental = GL_TRUE; //          useless in this version ?
            if (glewInit())
                p->exit_state = handle_error_sdl("Glew could not initialize.");
        }
    }
    return (p->exit_state);
}

int         launch_render(t_prog *p)
{
    init_t_prog(p);
    if (init_graphic_context(p) != -1)
        graphic_loop(p);
    return (p->exit_state);
}