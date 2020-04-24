/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:28:33 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:28:33 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
			f(&s[i++]);
	}
}
