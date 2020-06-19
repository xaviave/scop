/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:32:53 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:43:12 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void		key_callback(GLFWwindow *win, int key, int scancode,
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GLFW_TRUE);
	if (scancode || mods)
		return ;
}

void		mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
	if (window || xpos || ypos)
		return ;
}

void		error_callback(int error, const char *description)
{
	printf("Error %d: %s\n", error, description);
}
