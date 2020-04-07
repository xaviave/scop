#include "../../includes/scop.h"
#include "../../includes/parser_struct.h"

void        *addr_add(void *content, int type, t_addr **addr)
{
    t_addr  *new;

    if (!(content) || !(new = (t_addr*)malloc(sizeof(t_addr))))
        return (NULL);
    new->content_addr = content;
    new->content_type = type;
    new->next = *addr;
    *addr = new;
    return (content);
}
