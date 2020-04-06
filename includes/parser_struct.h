/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:14:29 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/05 12:49:06 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include "scop.h"

/*
** Defines
*/

# define ID_VT 0
# define ID_VN 1
# define ID_V 2
# define ID_F 3
# define ID_L 4
# define ID_MTL 5
# define ID_ERR_OBJ 6
# define ID_G 7
# define ID_O 8

# define ID_KA 0
# define ID_KD 1
# define ID_KS 2
# define ID_TF 3
# define ID_D 4
# define ID_NS 5
# define ID_SHARP 6
# define ID_NI 7
# define ID_BUMP 8
# define ID_DECAL 9
# define ID_DISP 10
# define ID_ILLUM 11
# define ID_ERR_MTL 12

# define P_OBJ 0
# define P_MTL 1

// image file type
# define F_BMP 0
# define F_PNG 1
# define F_JPEG 2
# define F_JPG 3
// compiled procedural texture files
# define F_CXC 4
# define F_CXS 5
# define F_CXB 6
// mip-mapped texture files
# define F_MPC 7
# define F_MPS 8
# define F_MPB 9
// spectral Curve File | could not be parse
# define F_RFL 10

/*
** Structures
*/

typedef struct				s_parser
{
	int						nb_args;
	char					**path;
	char					**args;
    t_addr                  *addr;
	t_obj					*obj;
	t_mtl					*mtl;
}							t_parser;

#endif