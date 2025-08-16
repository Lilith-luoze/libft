/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_basic_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:23:30 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/16 22:23:31 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/*create node*/
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

/*add an existing node to the front */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	/*update the head (this is why we need pass t_list **)*/
	*lst = new;
}

/*add an existing node to the back.
if the list is empty, make the node the head */
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

/* count the number of nodes of a list*/
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

/*go to a list's last node*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

