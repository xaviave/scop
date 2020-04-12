/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_delete_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:37:15 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:37:19 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "cleaner.h"

void            delete_str_tab(char **tab)
{
    int         i;

    i = 0;
    while (tab[i])
        ft_strdel(&tab[i++]);
    free(tab);
    tab = NULL;
}

void            delete_list_parser(t_list_parser **list)
{
    if (*list)
    {
        ft_strdel(&(*list)->data);
        if ((*list)->next)
            delete_list_parser(&((*list)->next));
        ft_memdel((void **)list);
    }
}

void            delete_texture_option(t_texture_option *to)
{
    ft_memdel((void **)&to->mm);
    ft_memdel((void **)&to->o);
    ft_memdel((void **)&to->s);
    ft_memdel((void **)&to->t);
}

void			delete_img(t_img img)
{
	ft_memdel((void **)&img.data);
}

void            delete_t_file(t_file *file)
{
    ft_strdel(&file->name);
    ft_strdel(&file->path);
	delete_img(file->img);
}
