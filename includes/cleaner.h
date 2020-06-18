#ifndef CLEANER_H
# define CLEANER_H

/*
** Structures
*/

/*
** Functions
*/

void	free_str(char *str);
void	*addr_add(void *content, int type, t_addr **addr);
void	delete_addr(t_addr **addr);
void	delete_addr_render(t_addr **addr);
void	delete_t_transparent(t_transparent *obj);
void	delete_t_specular_exponent(t_specular_exponent *obj);
void	delete_t_bump(t_bump *obj);
void	delete_t_disp(t_disp *obj);
void	delete_t_decal(t_decal *obj);
void	delete_list_parser(t_list_parser **list);
void	delete_texture_option(t_texture_option *to);
void	delete_t_file(t_file *file);
void	delete_str_tab(char **tab);
void	delete_tab_len(char **tab, int len);

#endif
