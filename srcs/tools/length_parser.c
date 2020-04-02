/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:27:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/03/22 17:25:33 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static int                  calc_id_g(t_list_parser *tmp)
{
    int     i;
    int     id;

    i = 0;
    id = tmp->id;
    while (tmp)
    {
        if (tmp->id == id)
            i++;
        else if (tmp->id != ID_ERR)
            break ;
        tmp = tmp->next;
    }
    return (i);
}

static int                  calc_id_o(t_list_parser *tmp)
{
    int     i;
    int     id;

    i = 0;
    id = tmp->id;
    if (id == ID_G)
        return (1);
    while (tmp)
    {
        if (tmp->id == ID_O)
            break ;
        else if (tmp->id != ID_ERR)
        {
            i++;
            if (tmp->id == ID_G)
                break ;
        }
        tmp = tmp->next;
    }
    if ((tmp == NULL && i == 0) || (tmp && tmp->id == ID_O && i == 0))
        handle_error_parser("Syntax error.", NULL);
    return (i);
}

int							len_list_parser_id(t_list_parser *list)
{
	t_list_parser			*tmp;

	if (list->next == NULL)
	{
	    ft_printf("%s\n", list->data);
        handle_error_parser("Error in line", NULL);
    }
	tmp = list->next;
	while (tmp && tmp->id == ID_ERR)
	    tmp = tmp->next;
	if (tmp == NULL)
	{
        ft_printf("%s\n", list->data);
        handle_error_parser("Error in line", NULL);
    }
    return (list->id == ID_O ? calc_id_o(tmp) : calc_id_g(tmp));
}
