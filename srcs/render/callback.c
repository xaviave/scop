/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:23:12 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/23 19:25:36 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		key_callback(GLFWwindow *win, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
	if (scancode || mods)
		return ;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (window || xpos || ypos)
		return ;
}

void		error_callback(int error, const char* description)
{
	ft_printf("Error %d: %s\n", error, description);
}
