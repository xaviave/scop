/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:03:40 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/23 11:37:23 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/*
** RENDER.H
*/

/*
** Internal Libraries
*/

# include "parser_struct.h"
# include "render_struct.h"
# include "tools.h"
# include "cleaner.h"
# include "error.h"

/*
** Functions
*/

int		launch_render(t_gdata *gdata, t_parser *parser);
void	key_callback(GLFWwindow* window, int key,
	int scancode, int action, int mods);
void	error_callback(int error, const char* description);
void	init_shader(t_engine *e);
void	load_texture(t_gdata *gdata, char *name, unsigned int t);
void	create_texture(t_gdata *gdata, char *name, unsigned int t);

#endif
