#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlinked_list
{
	void *content;
	struct s_dlinked_list *next;
	struct s_dlinked_list *prev;
} t_dlinked_list;

t_dlinked_list *ft_new_node(void *content);
void ft_add_node_to_back(t_dlinked_list **lst, t_dlinked_list *newnode);
void ft_remove_one(t_dlinked_list *lst, void (*del)(void *));
void ft_remove_from_front(t_dlinked_list **lst, void (*del)(void *));
int ft_lst_size(t_dlinked_list *lst);
void ft_list_clear(t_dlinked_list **lst, void (*del)(void *));
#endif