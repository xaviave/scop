/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 22:44:10 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/15 19:01:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "render.h"

static int	init_graphic_context(t_gdata *gdata)
{
	int 	width;
	int		height;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		// need to free obj and mtl
		return (0);	
	}
	gdata->win = glfwCreateWindow(W, H, PROG_NAME, NULL, NULL);
	if (!gdata->win)
	{
		// need to free obj and mtl
		return (0);	
	}
	glfwSetKeyCallback(gdata->win, key_callback);
	glfwMakeContextCurrent(gdata->win);
    glfwSwapInterval(1);

	glfwGetFramebufferSize(gdata->win, &width, &height);
	glViewport(0, 0, width, height);
	gdata->time = glfwGetTime();
	return (1);
}

int			init_gdata(t_gdata *gdata, t_parser *parser)
{
    gdata->obj = parser->obj;
    gdata->mtl = parser->mtl;
	return (init_graphic_context(gdata));
}
