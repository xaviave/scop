#include "parser.h"

int         check_header_newmtl(char **content, t_status *current)
{
    (void)content;
    if (current->tab_len != 2)
        return (0);
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
    current->len_mtl++;
    return (1);
}

int         check_header_k_tf(char **content, t_status *current)
{
    int     i;

    i = 0;
    if (current->tab_len != 4 || !current->len_mtl)
        return (0);
    if (content[0][1] == 'a')
        current->ka = current->ka == TRUE ? -1 : TRUE;
    else if (content[0][1] == 'd')
        current->kd = current->kd == TRUE ? -1 : TRUE;
    else if (content[0][1] == 's')
        current->ks = current->ks == TRUE ? -1 : TRUE;
    else if (content[0][1] == 'f')
        current->tf = current->tf == TRUE ? -1 : TRUE;
    if (current->ka == -1 || current->kd == -1
            || current->ks == -1 || current->tf == -1)
        return (0);
    while (++i < 4)
        if (!is_num_or_float(content[i]))
            return (0);
    return (1);
}

int         check_header_n_d_tr(char **content, t_status *current)
{
    int     i;

    i = 0;
    if (current->tab_len != 2 || !current->len_mtl)
        return (0);
    if (content[0][0] == 'd')
        current->d = current->d == TRUE ? -1 : TRUE;
    else if (content[0][1] == 'r')
        current->tr = current->tr == TRUE ? -1 : TRUE;
    else if (content[0][1] == 'i')
        current->ni = current->ni == TRUE ? -1 : TRUE;
    else if (content[0][1] == 's')
        current->ns = current->ns == TRUE ? -1 : TRUE;
    if (current->d == -1 || current->tr == -1
            || current->ns == -1 || current->ni == -1)
        return (0);
    if (!is_num_or_float(content[1]))
        return (0);
    return (1);
}

int         check_header_illum(char **content, t_status *current)
{
    int     i;

    i = 0;
    if (current->tab_len != 2 || !current->len_mtl)
        return (0);
    current->illum = current->illum == TRUE ? -1 : TRUE;
    if (current->illum == -1)
        return (0);
    if (!is_num_or_float(content[1]))
        return (0);
//    if (!ft_strcmp(content[1], "2") && current->ks != TRUE)
//        return (0); // need Ks line before illum if illum is 2
    return (1);
}

int         check_header_map_(char **content, t_status *current)
{
    int     i;

    i = 0;
    if (current->tab_len < 2 || !current->len_mtl)
        return (0);
    if (!ft_strcmp(content[0], "map_Ka"))
        current->map_[0] = current->map_[0] == TRUE ? -1 : TRUE;
    else if (!ft_strcmp(content[0], "map_Kd"))
        current->map_[1] = current->map_[1] == TRUE ? -1 : TRUE;
    else if (!ft_strcmp(content[0], "map_Ks"))
        current->map_[2] = current->map_[2] == TRUE ? -1 : TRUE;
    else if (!ft_strcmp(content[0], "map_Ns"))
        current->map_[3] = current->map_[3] == TRUE ? -1 : TRUE;
    else if (!ft_strcmp(content[0], "map_d"))
        current->map_[4] = current->map_[4] == TRUE ? -1 : TRUE;
    else if (!ft_strcmp(content[0], "map_Bump"))
        current->map_[5] = current->map_[5] == TRUE ? -1 : TRUE;
    else
        return (0);
    while (i < 8)
        if (current->map_[i++] == -1)
            return (0);
    if (ft_strncmp(ft_strrev(content[current->tab_len - 1]), "pmb.", 4))
        return (0);
    return (1);
}
