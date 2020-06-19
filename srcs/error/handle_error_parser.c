/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:56:28 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 17:28:45 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "error.h"
#include "cleaner.h"

void			delete_t_mtl(t_mtl mtl)
{
	delete_tab_len(mtl.groups, mtl.nb_groups);
	if (mtl.ac)
		delete_texture_option(&mtl.ac->option);
	ft_memdel((void **)&mtl.ac);
	if (mtl.dc)
		delete_texture_option(&mtl.dc->option);
	ft_memdel((void **)&mtl.dc);
	if (mtl.sc)
		delete_texture_option(&mtl.sc->option);
	ft_memdel((void **)&mtl.sc);
	if (mtl.tf)
		delete_t_file(&mtl.tf->file);
	ft_memdel((void **)&mtl.tf);
	delete_t_transparent(mtl.t);
	delete_t_specular_exponent(mtl.se);
	delete_t_bump(mtl.bump);
	delete_t_disp(mtl.disp);
	delete_t_decal(mtl.decal);
	ft_memdel((void **)&mtl.od);
	ft_memdel((void **)&mtl.sharpness);
	ft_memdel((void **)&mtl.shading);
}

static void		delete_obj_memory(t_obj obj)
{
	ft_memdel((void **)&obj.vertices);
	ft_memdel((void **)&obj.indices);
	ft_memdel((void **)&obj.uv);
	ft_memdel((void **)&obj.faces);
	ft_memdel((void **)&obj.groups);
	ft_memdel((void **)&obj.lines);
	ft_memdel((void **)&obj.normals);
	ft_memdel((void **)&obj.objects);
	ft_memdel((void **)&obj.textures);
	ft_memdel((void **)&obj.vertexes);
}

void			delete_t_obj(t_obj obj)
{
	int			i;

	ft_strdel(&obj.mtllib);
	delete_tab_len(obj.mtl, obj.len_mtl);
	i = -1;
	while (++i < obj.len_faces)
	{
		ft_memdel((void **)&obj.faces[i].vertexes_id);
		ft_memdel((void **)&obj.faces[i].textures_id);
		ft_memdel((void **)&obj.faces[i].normals_id);
	}
	i = -1;
	while (++i < obj.len_groups)
		ft_strdel(&obj.groups[i].name);
	i = -1;
	while (++i < obj.len_lines)
	{
		ft_memdel((void **)&obj.lines[i].vertexes_id);
		ft_memdel((void **)&obj.lines[i].textures_id);
	}
	i = -1;
	while (++i < obj.len_objects)
		ft_strdel(&obj.objects[i].name);
	delete_obj_memory(obj);
}

void			delete_addr(t_addr **addr)
{
	int			i;

	if (*addr)
	{
		i = 0;
		if ((*addr)->content_type == M_CHAR__)
			delete_str_tab((char **)(*addr)->content_addr);
		else if ((*addr)->content_type == M_L_PAR_)
			delete_list_parser((t_list_parser **)&(*addr)->content_addr);
		else if ((*addr)->content_type == M_OBJ_)
		{
			while (i < ((t_obj *)(*addr)->content_addr)->nb_args)
				delete_t_obj(((t_obj *)(*addr)->content_addr)[i++]);
			ft_memdel((void **)&(*addr)->content_addr);
		}
		else if ((*addr)->content_type == M_MTL_)
		{
			while (i < ((t_mtl *)(*addr)->content_addr)->nb_args)
				delete_t_mtl(((t_mtl *)(*addr)->content_addr)[i++]);
			ft_memdel((void **)&(*addr)->content_addr);
		}
		if ((*addr)->next)
			delete_addr(&((*addr)->next));
		ft_memdel((void **)addr);
	}
}

void			handle_error_parser(char *message, t_addr **addr)
{
	printf("%s\n", message);
	if (addr)
		delete_addr(addr);
	exit(EXIT_FAILURE);
}
