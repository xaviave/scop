/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/21 16:58:50 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void				parser_f(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_f | line: %s | obj = %p | id = %d\nNo parsing\n", raw_data, obj, id);
}

void				parser_l(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_l | line: %s | obj = %p | id = %d\nNo parsing\n", raw_data, obj, id);
}

void				parser_o(t_obj *obj, char *raw_data, int id, int nb_id)
{
	// the id define the first id of the componnent | nb_id is the nb of compnnent in the group
    ft_printf("parser_o | line: %s | obj = %p | id = %d | nb_id = %d\nNo parsing\n", raw_data, obj, id, nb_id);
}

void				parser_g(t_obj *obj, char *raw_data, int id, int nb_id)
{
    ft_printf("parser_g | line: %s | obj = %p | id = %d | nb_id = %d\nNo parsing\n", raw_data, obj, id, nb_id);
}

void				parser_pass(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_pass | line: %s | obj = %p | id = %d\nNo parsing\n", raw_data, obj, id);
}