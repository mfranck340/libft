/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:38:41 by ffierro-          #+#    #+#             */
/*   Updated: 2024/09/28 00:46:40 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_memory(t_list *list, void (*del)(void *), void *tmp)
{
	ft_lstclear(&list, del);
	del(tmp);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*list;
	void	*tmp;

	if (!lst)
		return (0);
	tmp = f(lst->content);
	list = ft_lstnew(tmp);
	if (!list)
	{
		del(tmp);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
			return (free_memory(list, del, tmp));
		ft_lstadd_back(&list, new_node);
		lst = lst->next;
	}
	return (list);
}
