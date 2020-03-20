/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier_martin <xavier_martin@student.le    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:43:27 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/20 15:51:45 by xavier_mart      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void			init_ptr(void (*f[7])(t_obj *, char *))
{
	f[0] = &parser_vt;
	f[1] = &parser_vn;
	f[2] = &parser_vp;
	f[3] = &parser_v;
	f[4] = &parser_f;
	f[5] = &parser_l;
	f[6] = &parser_pass;
}

/*
** check_obj simply check the lenght of every obj
** if a len is NULL, it's due to an error during the parsing
*/

static int			check_obj(t_obj *obj)
{
	short			err;

	err = 1;
	err = (obj->len_faces) ? 1 : 0;
	err = (err && obj->len_groups) ? 1 : 0;
	err = (err && obj->len_lines) ? 1 : 0;
	err = (err && obj->len_normals) ? 1 : 0;
	err = (err && obj->len_objects) ? 1 : 0;
	err = (err && obj->len_space_vertexes) ? 1 : 0;
	err = (err && obj->len_textures) ? 1 : 0;
	err = (err && obj->len_vertexes > 2) ? 1 : 0;
	return (err);
}

static int			list_parser_to_obj(t_obj *obj, t_list_parser *list)
{
	short			err;
	void			(*f[7])(t_obj *, char *);
	t_list_parser	*tmp;

	err = 0;
	tmp = list;
	init_ptr(f);
	init_obj(obj);
	while (tmp->next)
	{
		if (err <= tmp->id || err < 4)
		{
			err = tmp->id;
			f[tmp->id](obj, tmp->data);
		}
		tmp = list->next;
		free(list->data);
		free(list);
	}
	return (check_obj(obj));
}

static void			open_file(int fd, int obj_index, t_parser *parser)
{
	int				i;
	char			*line;
	t_list_parser	*list;

	i = 0;
	ft_printf("Parsing file: %s\n", parser->args[obj_index]);
	while(get_next_line(fd, &line))
	{
		if (ft_strlen(line) && ft_strchr(line, '#'))
			add_list_parser(&list, line);			
		else
		{
			ft_printf("ENTER HERE FOR COMMENT\n");
			free(line);
		}
	}
	if (list_parser_to_obj(&parser->obj[obj_index], list))
		handle_error_parser("Error durring Parsing");
	ft_printf("NEED TO FREE T_LIST_PARSER - reader.c l.26");
}

/*
**	Allow multiple file opening
*/

void				reader(t_parser *parser)
{
	int				i;
	int				fd;
	
	i = 0;
	while (++i < parser->nb_args)
	{
		fd = open(parser->args[i], O_RDONLY);
		open_file(fd, i, parser);
	}
}
