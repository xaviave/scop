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

// static int					check_color(char *raw_data)
// {
// 	int						tmp;

// 	tmp = ft_atoi(raw_data);
// 	if (tmp == 0 || tmp == 1)
// 		return (1);
// 	return (0);
// }


static int          dispatch_by_header(char **content, t_parser_option *opt,
        t_status *current)
{
    int             i;

    i = 0;
    if (!ft_strcmp(content[0], "newmtl"))
    {
        if (current->tab_len != 2)
            return (0);
        current->ka = FALSE;
        current->kd = FALSE;
        current->ks = FALSE;
        current->d = FALSE;
        current->tr = FALSE;
        current->ns = FALSE;
        current->illum = FALSE;
        current->map = FALSE;
        while (i < current->len_mtl)
            if (!ft_strcmp(current->mtl_name[i++], content[1]))
                return (0);
        current->mtl_name[current->len_mtl] = ft_strdup(content[1]);
        current->len_mtl++;
    }
    else if (!ft_strcmp(content[0], "Ka") || !ft_strcmp(content[0], "Kd") || !ft_strcmp(content[0], "Ks"))
    {
        if (current->tab_len != 4)
            return (0);
        if (content[0][1] == 'a')
            current->ka = current->ka == TRUE ? -1 : TRUE;
        else if (content[0][1] == 'd')
            current->kd = current->kd == TRUE ? -1 : TRUE;
        else if (content[0][1] == 's')
            current->ks = current->ks == TRUE ? -1 : TRUE;
        if (current->ka == -1 || current->kd == -1 || current->ks == -1)
            return (0);
        while (++i < 4)
            if (!is_num_or_float(content[i]))
                return (0);
    }
    else if (!ft_strcmp(content[0], "d") || !ft_strcmp(content[0], "Tr") || !ft_strcmp(content[0], "Ns"))
    {
        if (current->tab_len != 2)
            return (0);
        if (content[0][0] == 'd')
            current->d = current->d == TRUE || current->tr == TRUE ? -1 : TRUE;
        else if (content[0][1] == 'r')
            current->tr = current->tr == TRUE || current->d == TRUE ? -1 : TRUE;
        else
            current->ns = current->ns == TRUE ? -1 : TRUE;
        if (current->d == -1 || current->tr == -1 || current->ns == -1)
            return (0);
        if (!is_num_or_float(content[1]))
            return (0);
    }
    else if (!ft_strcmp(content[0], "illum"))
    {
        if (current->tab_len != 2)
            return (0);
        current->illum = current->illum == TRUE ? -1 : TRUE;
        if (current->illum == -1)
            return (0);
        if (!is_num_or_float(content[1]))
            return (0);
        if (!ft_strcmp(content[1], "2") && current->ks != TRUE)
            return (0);
    }
    return (1);
}

int					check_mtl_raw_data(char *raw_data, t_parser_option *opt)
{
    int             i;
    char            **content;
    static t_status current;

    printf("\n\nnum of mtl in file %d\n     raw_len %d - raw_data %s\n", current.len_mtl, opt->data_len, raw_data);
    content = ft_strsplit(change_chr(raw_data, '\t', ' '), ' ');
    current.tab_len = len_tab(content);

    i = 0;
    while (content[i])
        printf("%s|", content[i++]);

    if (content[0][0] == '#')
        return (1);
    if (!dispatch_by_header(content, opt, &current))
        return (0);
	return (1);
}