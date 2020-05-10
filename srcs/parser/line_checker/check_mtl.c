/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:18:48 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/12 18:35:01 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int          check_pass_line(char **content)
{
    // line not parsed but valid.
    if (!ft_strcmp(content[0], "Ke") || content[0][0] == '#')
        return (1);
    // else error.
    return (0);
}

static int          dispatch_by_header(char **content, t_status *current)
{
    if (!ft_strcmp(content[0], "newmtl"))
        return (check_header_newmtl(content, current));
    else if (!ft_strcmp(content[0], "Ka") || !ft_strcmp(content[0], "Kd")
            || !ft_strcmp(content[0], "Ks") || !ft_strcmp(content[0], "Tf"))
        return (check_header_k_tf(content, current));
    else if (!ft_strcmp(content[0], "d") || !ft_strcmp(content[0], "Tr")
            || !ft_strcmp(content[0], "Ns") || !ft_strcmp(content[0], "Ni"))
        return (check_header_n_d_tr(content, current));
    else if (!ft_strcmp(content[0], "illum"))
        return (check_header_illum(content, current));
    else if (!ft_strncmp(content[0], "map_", 4))
        return (check_header_map_(content, current));
   return (check_pass_line(content));
}

int					check_mtl_raw_data(char *raw_data, t_parser_option *opt)
{
    int             ret;
    int             i;
    char            **content;
    static t_status current;

    (void)opt;
    i = 0;
    if (!(content = ft_strsplit(change_chr(raw_data, '\t', ' '), ' ')))
    {
//        while (i < 256)
//            ft_strdel(&current.mtl_name[i++]);
        return (0);
    }
    current.tab_len = len_tab(content);
    ret = dispatch_by_header(content, &current);
    delete_str_tab(content);
//    while (i < 256)
//    {
//        ft_putendl(current.mtl_name[i]);
//        i++;
//        ft_strdel(&current.mtl_name[i++]);
//    }
// need to recode the mtl_name tab.
    return (ret);
}