/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_f_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 14:41:16 by xavier_mart       #+#    #+#             */
/*   Updated: 2020/03/20 20:31:24 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void				parser_f(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_f | line: %s | obj = %p\nNo parsing\n", raw_data, obj[id]);
}

void				parser_l(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_l | line: %s | obj = %p\nNo parsing\n", raw_data, obj[id]);

}

void				parser_pass(t_obj *obj, char *raw_data, int id)
{
    ft_printf("parser_pass | line: %s | obj = %p\nNo parsing\n", raw_data, obj[id]);
}
