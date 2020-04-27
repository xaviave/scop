/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 14:54:07 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:37:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int			get_mtl_id(char tmp[3])
{
	if (ft_strstr(tmp, "Ka"))
		return (ID_KA);
	else if (ft_strstr(tmp, "Kd"))
		return (ID_KD);
	else if (ft_strstr(tmp, "Ks"))
		return (ID_KS);
	else if (ft_strstr(tmp, "Tf"))
		return (ID_TF);
	else if (ft_strstr(tmp, "d"))
		return (ID_D);
	else if (ft_strstr(tmp, "Ns"))
		return (ID_NS);
	else if (ft_strstr(tmp, "sh"))
		return (ID_SHARP);
	else if (ft_strstr(tmp, "Ni"))
		return (ID_NI);
	else if (ft_strstr(tmp, "bu"))
		return (ID_BUMP);
	else if (ft_strstr(tmp, "de"))
		return (ID_DECAL);
	else if (ft_strstr(tmp, "il"))
		return (ID_ILLUM);
	return (ID_ERR_MTL);
}

int					define_id_mtl(char *raw_data)
{
	char			tmp[6];

	ft_bzero(&tmp, 6);
	if (ft_strstr(raw_data, "map_"))
		ft_strncpy(tmp, &raw_data[4], 2);
	else
		ft_strncpy(tmp, raw_data, 2);
	return (get_mtl_id(tmp));
}

int					define_id_obj(char *raw_data, t_parser_option *opt)
{
	char			tmp[3];
	int				id;

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
		id = ID_ERR_OBJ;
	opt->len[id]++;
	return (id);
}
