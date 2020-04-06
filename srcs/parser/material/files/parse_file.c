/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:04:16 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:27:49 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/parser.h"

static int					define_file_type(char *type)
{
	ft_printf("type = %s\n", type);
	if (!ft_strcmp(type, "rfl"))
		handle_error_parser("Line error | can't parse RFL file, private WaveFront technologie lol\n", NULL);
	else if (!ft_strcmp(type, "bmp"))
		return (F_BMP);
	else if (!ft_strcmp(type, "png"))
		return (F_PNG);
	else if (!ft_strcmp(type, "jpg"))
		return (F_JPG);
	else if (!ft_strcmp(type, "jpeg"))
		return (F_JPEG);
	else if (!ft_strcmp(type, "cxc"))
		return (F_CXC);
	else if (!ft_strcmp(type, "cxs"))
		return (F_CXS);
	else if (!ft_strcmp(type, "cxb"))
		return (F_CXB);
	else if (!ft_strcmp(type, "mps"))
		return (F_MPS);
	else if (!ft_strcmp(type, "mpb"))
		return (F_MPB);
	else if (!ft_strcmp(type, "mpc"))
		return (F_MPC);
	ft_printf("IF HERE NEED TO MAKE A FUCKIN PARSER_FILE_ERROR\n");
	return (10);
}

void						parse_file(t_file *file, char *raw_data)
{
	void					(*f[10])(t_file *);

	file->name = ft_strtrim(raw_data);
	file->type = define_file_type(&file->name[ft_strlen(file->name) - 3]);
	init_file_ptr(f);
	f[file->type](file);
}