/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:36:07 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:38:47 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static char			*get_shader(char *name)
{
	int				fd;
	int				ret;
	char			*tmp;
	char			*file;
	char			line[SHADER_READ];

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	if (!(file = ft_strnew(SHADER_READ)))
		return (close(fd) == -1 ? NULL : NULL);
	while ((ret = read(fd, &line, SHADER_READ)) > 0)
	{
		line[ret] = '\0';
		tmp = file;
		if (!(file = ft_strjoin(file, line)))
		{
			ft_strdel(&tmp);
			return (close(fd) == -1 ? NULL : NULL);
		}
		ft_strdel(&tmp);
	}
	close(fd);
	return (file);
}

static int			print_shader_error(GLint addr, int opt)
{
	char			info_log[1024];

	if (opt)
		glGetShaderInfoLog(addr, 1024, NULL, info_log);
	else
		glGetProgramInfoLog(addr, 1024, NULL, info_log);
	fprintf(stderr, "init_shader error: %s\n", info_log);
	return (0);
}

static int			init_program(t_engine *e, GLuint vs, GLuint fs)
{
	int				success;

	e->program = glCreateProgram();
	glAttachShader(e->program, vs);
	glAttachShader(e->program, fs);
	glLinkProgram(e->program);
	glGetProgramiv(e->program, GL_LINK_STATUS, &success);
	if (!success)
		return (print_shader_error(e->program, 0));
	return (1);
}

int					init_shader(t_engine *e)
{
	GLuint			vs;
	GLuint			fs;
	const GLchar	*shad;
	int				success;

	if (!(shad = get_shader("shaders/vertex_custom_shader")))
		return (0);
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &shad, NULL);
	ft_strdel((char **)&shad);
	if (!(shad = get_shader("shaders/fragment_custom_shader")))
		return (0);
	glCompileShader(vs);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &shad, NULL);
	ft_strdel((char **)&shad);
	glCompileShader(fs);
	glGetProgramiv(e->program, GL_LINK_STATUS, &success);
	if (!success)
		return (print_shader_error(e->program, 1));
	if (!(init_program(e, vs, fs)))
		return (0);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return (1);
}
