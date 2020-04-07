#include "../../includes/tools.h"
#include "../../includes/cleaner.h"

void            delete_list_parser(t_list_parser **list)
{
    if (*list)
    {
        ft_strdel(&(*list)->data);
        if ((*list)->next)
            delete_list_parser(&((*list)->next));
        free(*list);
        *list = NULL;

    }
}

void            delete_texture_option(t_texture_option *to)
{
    ft_memdel((void **)&to->mm);
    ft_memdel((void **)&to->o);
    ft_memdel((void **)&to->s);
    ft_memdel((void **)&to->t);
}

void            delete_t_file(t_file *file)
{
    ft_strdel(&file->name);
    ft_strdel(&file->path);
    ft_memdel((void **)&file->data);
}
