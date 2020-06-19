/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:56:14 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 14:56:14 by ltoussai         ###   ########lyon.fr   */
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
