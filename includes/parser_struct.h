/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltoussai <lotoussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:41:11 by ltoussai          #+#    #+#             */
/*   Updated: 2020/06/19 13:42:21 by ltoussai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include "scop.h"

/*
** Defines
*/

# define IMG_BUFFER 500000

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

/*
** DEFINE for memory allocation and keep address.
** Exemple: M_OBJ_   = memory_t_obj*
**          M_CHAR_  = memory_char*
**          M_CHAR__ = memory_char**
**          put '_' after the define for the number of *
*/

# define M_OBJ_ 0
# define M_CHAR__ 1
# define M_L_PAR_ 2
# define M_MTL_ 3

/*
** Structures
*/

typedef struct			s_addr
{
	void				*content_addr;
	int					content_type;
	struct s_addr		*next;
}						t_addr;

typedef struct			s_parser
{
	int					nb_args;
	char				**path;
	char				**args;
	t_addr				*addr;
	t_obj				*obj;
	t_mtl				*mtl;
}						t_parser;

#endif
