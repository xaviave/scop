/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_delete_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:56:20 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 19:56:27 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tools.h"
#include "../../includes/cleaner.h"

void			delete_t_transparent(t_transparent *obj)
{
	if (obj)
	{
		delete_t_file(&obj->file);
		delete_texture_option(&obj->option);
	}
	ft_memdel((void **)&obj);
}

void			delete_t_specular_exponent(t_specular_exponent *obj)
{
	if (obj)
	{
		delete_t_file(&obj->file);
		delete_texture_option(&obj->option);
	}
	ft_memdel((void **)&obj);
}

void			delete_t_bump(t_bump *obj)
{
	if (obj)
	{
		delete_t_file(&obj->file);
		delete_texture_option(&obj->option);
	}
	ft_memdel((void **)&obj);
}

void			delete_t_disp(t_disp *obj)
{
	if (obj)
	{
		delete_t_file(&obj->file);
		delete_texture_option(&obj->option);
	}
	ft_memdel((void **)&obj);
}

void			delete_t_decal(t_decal *obj)
{
	if (obj)
	{
		delete_t_file(&obj->file);
		delete_texture_option(&obj->option);
	}
	ft_memdel((void **)&obj);
}
