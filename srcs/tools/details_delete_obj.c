/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_delete_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:52:57 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:53:11 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"
#include "../../includes/cleaner.h"

void			delete_tab_len(char **tab, int len)
{
	int			i;

	i = 0;
	if (!tab)
		return ;
	while (i < len)
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

void			delete_str_tab(char **tab)
{
	int			i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

void			delete_list_parser(t_list_parser **list)
{
	if (*list)
	{
		ft_strdel(&(*list)->data);
		if ((*list)->next)
			delete_list_parser(&((*list)->next));
		ft_memdel((void **)list);
	}
}

void			delete_texture_option(t_texture_option *to)
{
	ft_memdel((void **)&to->mm);
	ft_memdel((void **)&to->o);
	ft_memdel((void **)&to->s);
	ft_memdel((void **)&to->t);
}

void			delete_t_file(t_file *file)
{
	t_img		img;

	ft_strdel(&file->name);
	ft_strdel(&file->path);
	img = file->img;
	ft_memdel((void **)&img.data);
}
