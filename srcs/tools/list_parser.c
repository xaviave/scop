/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/21 17:39:52 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static int					define_id(t_obj *obj, char *raw_data)
{
	if (ft_strstr(raw_data, "vt") && (obj->len_textures))
		return (0);
	else if (ft_strstr(raw_data, "vn") && (obj->len_normals))
		return (1);
	else if (ft_strstr(raw_data, "vp") && (obj->len_space_vertexes))
		return (2);
	else if (ft_strstr(raw_data, "v") && (obj->len_vertexes))
		return (3);
	else if (ft_strstr(raw_data, "f") && (obj->len_faces))
		return (4);
	else if (ft_strstr(raw_data, "l") && (obj->len_lines))
		return (5);
	else if (ft_strstr(raw_data, "g") && (obj->len_groups))
		return (7);
	else if (ft_strstr(raw_data, "o") && (obj->len_objects))
		return (8);
	else
		return (6);	
}

static t_list_parser		*new_list_parser(t_obj *obj, char *raw_data)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL);
	new->id = define_id(obj, raw_data);
	new->data = raw_data;
	new->next = NULL;
	return new;
}

void                        add_list_parser(t_obj *obj, t_list_parser **list, char *raw_data)
{
	t_list_parser			*tmp;

	if (!(*list))
		*list = new_list_parser(obj, raw_data);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list_parser(obj, raw_data);
	}
}

int							list_parser_len(t_list_parser **list)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


int							len_list_parser_id(t_list_parser *list, int id)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = list;
	while (tmp->next && tmp->next->id == id)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
