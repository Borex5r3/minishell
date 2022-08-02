#include "double_linked_list.h"

t_dlinked_list *ft_new_node(void *content)
{
	t_dlinked_list *newnode;
	
	newnode = (t_dlinked_list*)malloc(sizeof(t_dlinked_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void ft_add_node_to_back(t_dlinked_list **lst, t_dlinked_list *newnode)
{
	t_dlinked_list *tmp;
	
	if (!lst || !newnode)
		return ;
	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
	newnode->prev = tmp;
}

void ft_remove_one(t_dlinked_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	del(lst->content);
	free(lst);
}

void ft_remove_from_front(t_dlinked_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	ft_remove_one(*lst, del);
	*lst = (*lst)->next;
}

int ft_lst_size(t_dlinked_list *lst)
{
	int size;
	
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void ft_list_clear(t_dlinked_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	while (*lst)
		ft_remove_from_front(lst, del);

}