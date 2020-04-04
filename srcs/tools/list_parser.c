/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:39:32 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/26 10:27:32 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

static int				define_id(char *raw_data, t_parser_option *opt)
{
	char				tmp[3];
	int                 id;

	ft_bzero(&tmp, 3);
	ft_strncpy(tmp, raw_data, 2);
	if (ft_strlen(raw_data) > 7 && (ft_strstr(tmp, "us")))
		id = ID_MTL;
	else if (ft_strstr(tmp, "vt"))
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
	opt->len[id]++;
	return (id);
}

static t_list_parser	*new_list_parser(char *raw_data,
	t_parser_option *opt)
{
	t_list_parser		*new;

	if (!(new = (t_list_parser *)malloc(sizeof(t_list_parser))))
		return (NULL);
	new->id = define_id(raw_data, opt);
    if (!(new->data = ft_strdup(raw_data)))
    {
        free(&new);
        new = NULL;
        return (NULL);
    }
	new->next = NULL;
	opt->list_parser_len++;
	return (new);
}

void                    add_list_parser(t_list_parser **list,
        char *raw_data, t_parser_option *opt, t_addr **addr)
{
	t_list_parser		    *tmp;
	t_list_parser           *new;
	static t_list_parser    *last;

    if (!(new = new_list_parser(raw_data, opt)))
    {
        ft_strdel(&raw_data);
        handle_error_parser("Error during memory allocation.", addr);
    }
    if (!(*list))
    {
        *list = addr_add(new, M_L_PAR_, addr);
        last = *list;
    }
	else
	{
        last->next = new;
        last = last->next;
	}
}

int						list_parser_len(t_list_parser **list)
{
	int					i;
	t_list_parser		*tmp;

	i = 0;
	tmp = *list;
	while (tmp)
	{
        i++;
		tmp = tmp->next;
	}
	return (i);
}