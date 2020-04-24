/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:10:47 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/24 19:29:05 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

static char			*get_shader(char *name)
{
	int				fd;
	int				ret;	
	char			*tmp;
	char			*file;
	char			line[SHADER_READ];	

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = ft_strnew(SHADER_READ);
	while ((ret = read(fd, &line, SHADER_READ)) > 0)
	{
		line[ret] = '\0';
		tmp = file;
		file = ft_strjoin(file, line);
		ft_strdel(&tmp);
	}
	close(fd);
	return (file);
}

static void			init_program(t_engine *e, GLuint vs, GLuint fs)
{
    e->program = glCreateProgram();
    glAttachShader(e->program, vs);
    glAttachShader(e->program, fs);
    glLinkProgram(e->program);
 }

int					init_shader(t_engine *e)
{
	GLuint			vs;
	GLuint			fs;
	const GLchar	*s;
	const GLchar	*f;

	s = get_shader("shaders/vertex_custom_shader");
	f = get_shader("shaders/fragment_custom_shader");
	if (!s || !f)
		return (0);
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &s, NULL);
    glCompileShader(vs);
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &f, NULL);
    glCompileShader(fs);
	init_program(e, vs, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
	return (1);
}
