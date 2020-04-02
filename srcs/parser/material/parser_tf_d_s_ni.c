/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tf_d_s_ni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:15:13 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/02 19:02:39 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/scop.h"

void				parser_tf(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->tf =
		(t_transmission_filter *)ft_memalloc(sizeof(t_transmission_filter))))
        handle_error_parser("Error during memory allocation.");
	
}

void				parser_d(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->t = (t_transparent *)ft_memalloc(sizeof(t_transparent))))
        handle_error_parser("Error during memory allocation.");
    
}

void				parser_ns(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->se =
		(t_specular_exponent *)ft_memalloc(sizeof(t_specular_exponent))))
        handle_error_parser("Error during memory allocation.");
    
}

void				parser_ni(t_mtl *mtl, char *raw_data)
{
	if (!(mtl->od =
		(t_optical_density *)ft_memalloc(sizeof(t_optical_density))))
        handle_error_parser("Error during memory allocation.");
	
}
