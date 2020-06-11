#include "tools.h"
#include "error.h"
#include "cleaner.h"

void            travel_addr(t_addr *addr)
{
    if (addr->content_type == M_CHAR__)
    {
        addr->content_type = -1;
        delete_str_tab((char **)addr->content_addr);
    }
    else if (addr->content_type == M_L_PAR_)
    {
        addr->content_type = -1;
        delete_list_parser((t_list_parser **)&addr->content_addr);
    }
    if (addr->next)
        travel_addr(addr->next);
}

void            clear_parser_memory(t_addr **addr)
{
    if (addr)
        travel_addr(*addr);
}
