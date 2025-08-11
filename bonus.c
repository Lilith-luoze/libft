# include "libft.h"
#include "bonus.h"

t_list *ft_lstnew(void *content)
{
    t_list *node;  /*pointer to this t_list*/
    node = malloc(sizeof(t_list));
    if (!node)
        return(NULL);
    node ->content = content;
    node ->next = NULL;
    return (node);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    /*put the new to the front */
    new -> next = *lst;
    /*update the head (this is why we need pass t_list **)*/
    *lst = new; 
}

int ft_lstsize(t_list *lst)
{
    int size = 0;
    t_list * node;
    node = lst;
    while (node)
    {
        size++;
        node = node -> next;
    }
    return (size);
}

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while(lst -> next)
        lst = lst -> next;
    return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    if (!lst || !new)
        return;
    if (!(*lst))
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last -> next = new;
}

void ft_lstdelone(t_list *lst, void (*del)(void *))


void ft_lstclear(t_list **lst, void (*del)(void *))


void ft_lstiter(t_list *lst, void (*f)(void *));

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

