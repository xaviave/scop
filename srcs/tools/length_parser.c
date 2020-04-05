/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:27:28 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:29:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"

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
        else if (tmp->id != ID_ERR_OBJ)
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
        else if (tmp->id != ID_ERR_OBJ)
        {
            i++;
            if (tmp->id == ID_G)
                break ;
        }
        tmp = tmp->next;
    }
    if ((tmp == NULL && i == 0) || (tmp && tmp->id == ID_O && i == 0))
        handle_error_parser("Syntax error.\n");
    return (i);
}

int							len_list_parser_id(t_list_parser *list)
{
	t_list_parser			*tmp;

	if (list->next == NULL)
	    handle_error_parser("Syntax error line: %s\n", list->data);
	tmp = list->next;
	while (tmp && tmp->id == ID_ERR_OBJ)
	    tmp = tmp->next;
	if (tmp == NULL)
        handle_error_parser("Syntax error line: %s\n", list->data);
    return (list->id == ID_O ? calc_id_o(tmp) : calc_id_g(tmp));
}
