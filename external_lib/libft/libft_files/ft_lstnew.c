/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:14 by xamartin          #+#    #+#             */
/*   Updated: 2020/06/24 13:09:45 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = (NULL);
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = (NULL);
	return (new);
}
