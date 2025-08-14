
#include "libft.h"


static void	ft_init_vars(t_list **out, t_list **tail, t_list **node, void **cnt)
{
	*out = NULL;
	*tail = NULL;
	*node = NULL;
	*cnt = NULL;
}
/* creates a new list with new content (original untouched).*/
/*  1. conditionals in the loop to specify the header(out).
	2. del() the content only half-way inside the new node.*/
static void ft_append_n_update(t_list **out, t_list **tail, t_list	**node, t_list **lst)
{
	if (!(*out))
		*out = *node;
	else
		(*tail)->next = *node;
	*tail = *node;
	*lst = (*lst) -> next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*tail;
	t_list	*node;
	void	*cnt;

	if (!f || !del)
		return (NULL);
	ft_init_vars(&out, &tail, &node, &cnt);
	while (lst)
	{
		cnt = f(lst->content);
		node = ft_lstnew(cnt);
		if (!cnt || !node)
		{
			if (cnt)
				del(cnt);
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_append_n_update(&out,  &tail, &node, &lst);
	}
	return (out);
}
