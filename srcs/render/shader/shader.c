/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:10:47 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/20 18:42:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "render.h"

static char			*get_shader(char *name)
{
	int				fd;
	char			line[500];	
	int				ret;	
	char			*tmp;
	char			*file;

	fd = open(name, O_RDONLY);
	ft_printf("%s %d\n", name, fd);
	file = ft_strnew(500);
	while ((ret = read(fd, &line, 500)) > 0)
	{
		line[ret] = '\0';
		tmp = file;
		file = ft_strjoin(file, line);
		ft_strdel(&tmp);
	}
	close(fd);
	return (file);
}

static void	init_program(t_engine *e, GLuint vs, GLuint fs)
{
    e->program = glCreateProgram();
    glAttachShader(e->program, vs);
    glAttachShader(e->program, fs);
    glLinkProgram(e->program);
 }

void		init_shader(t_engine *e)
{
	GLuint	vs;
	GLuint	fs;
	const GLchar *s;
	const GLchar *f;

	s = get_shader("shaders/vertex_shader");
	f = get_shader("shaders/fragment_shader");
	// s = get_shader("shaders/basic_ok_vertex");
	// f = get_shader("shaders/basic_ok_fragment");
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &s, NULL);
    glCompileShader(vs);
    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &f, NULL);
    glCompileShader(fs);
	init_program(e, vs, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
}
