#ifndef ERROR_H
# define ERROR_H

# include "../external_lib/libft/header/libft.h"
# include "parser_struct.h"

/*
** Functions
*/

void	handle_error_parser(char *message, t_addr **addr);
void	handle_error_render(char *message, t_addr **addr);

#endif
