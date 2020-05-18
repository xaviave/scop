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

int                 check_duplicate_newmtl(char *new_mtl, int len_mtl,
        t_list **alst)
{
    t_list          *tmp;
    t_list          *new;

    if (!(new = ft_lstnew(new_mtl, sizeof(new_mtl))))
    {
        ft_printf("Error during memory allocation.\n");
        return (0);
    }
    ft_lstadd(alst, new);
    if (!len_mtl)
        return (1);
    tmp = *alst;
    while ((tmp = tmp->next))
        if (!ft_strcmp(tmp->content, new_mtl))
            return (0);
    return (1);
}

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

static void         init_current(t_status *current, t_parser_option *opt)
{
    if (opt->index == 0)
        current->index = 0;
    if (opt->index != current->index)
    {
        current->mtl_name = NULL;
        current->len_mtl = FALSE;
        current->ka = FALSE;
        current->kd = FALSE;
        current->ks = FALSE;
        current->d = FALSE;
        current->tr = FALSE;
        current->tf = FALSE;
        current->ns = FALSE;
        current->ni = FALSE;
        current->illum = FALSE;
        ft_bzero(current->map_, sizeof(current->map_));
        current->index = opt->index;
    }
}

int					check_mtl_raw_data(char *raw_data,
        t_parser_option *opt, t_addr **addr)
{
    int             ret;
    char            **content;
    static t_status current;

    (void)opt;
    init_current(&current, opt);
    if (!(content = ft_strsplit(change_chr(raw_data, '\t', ' '), ' ')))
        return (0);
    current.tab_len = len_tab(content);
    ret = dispatch_by_header(content, &current);
    delete_str_tab(content);
    if (current.len_mtl == 1 && ft_strstr(raw_data, "newmtl"))
        if (!(addr_add(current.mtl_name, M_LIST_, addr)))
        {
            ft_strdel((char **)&current.mtl_name->content);
            ft_memdel((void **)&current.mtl_name);
            return (0);
        }
    return (ret);
}