#include "../../includes/render.h"

int     handle_error_sdl(char *message, ...)
{
	ft_printf("%s\n", message);
	return (-1);
}
