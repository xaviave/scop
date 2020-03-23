/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/22 21:57:10 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static int					define_id(char *raw_data)
{
	char					tmp[3];
	int                     id;

	ft_bzero(&tmp, 3);
	ft_strncpy(tmp, raw_data, 2);
	if (ft_strstr(tmp, "vt"))
	    id = ID_VT;
	else if (ft_strstr(tmp, "vn"))
        id = ID_VN;
	else if (ft_strstr(tmp, "v"))
        id = ID_V;
	else if (ft_strstr(tmp, "f"))
        id = ID_F;
	else if (ft_strstr(tmp, "l"))
        id = ID_L;
	else if (ft_strstr(tmp, "g"))
        id = ID_G;
	else if (ft_strstr(tmp, "o"))
        id = ID_O;
	else
	    id = ID_ERR;
	return (id);
}

static t_list_parser		*new_list_parser(char *raw_data)
{
	t_list_parser			*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL); // return NULL ? handled in previous call or better call handel_error_parse ?
	new->id = define_id(raw_data);
    new->data = ft_strdup(raw_data);
	new->next = NULL;
	return (new);
}

void                        add_list_parser(t_list_parser **list, char *raw_data)
{
	t_list_parser			*tmp;

	if (!(*list))
		*list = new_list_parser(raw_data);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list_parser(raw_data);
	}
}

int							list_parser_len(t_list_parser **list)
{
	int						i;
	t_list_parser			*tmp;

	i = 0;
	tmp = *list;
	while (tmp)
	{
        i++;
		tmp = tmp->next;
	}
	return (i);
}