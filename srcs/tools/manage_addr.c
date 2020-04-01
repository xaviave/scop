#include "../../includes/scop.h"

void        *addr_add(void *content, char *type, t_addr **addr)
{
    t_addr  *new;

    if (!(content) || !(new = (t_addr*)malloc(sizeof(t_addr))))
        return (NULL);
    new->content_addr = &content;
    new->content_type = ft_strdup(type); // better add an int with a define
    new->next = *addr;
    *addr = new;
    return (content);
}
