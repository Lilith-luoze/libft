#include "bonus.h"
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node; /*pointer to this t_list*/
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	/*put the new to the front */
	new->next = *lst;
	/*update the head (this is why we need pass t_list **)*/
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*node;

	size = 0;
	node = lst;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*delete teh content, free the node (no need for linking?)*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*delete and free the given nodes 's content and itself,
	as well as its successors.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* creates a new list with new content (original untouched).*/
/*  1. conditionals in the loop to specify the header(out).
    2. del() the content only half-way inside the new node.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *out;
    t_list *tail;
    t_list *temp;
    void *cnt;
	if ( !f || !del)
		return (NULL);
    out = NULL;
	while (lst)
	{
        cnt = f(lst -> content);
        temp = ft_lstnew(cnt);        
        if (!temp)
        {
            del(cnt);
            ft_lstclear(&out , del);
            return NULL;
        }
        if (!out)
            out = temp;
        else
            tail -> next = temp;
        tail = temp;
        lst = lst -> next;
	}
	return (out);
}
