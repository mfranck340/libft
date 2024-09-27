/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:38:06 by ffierro-          #+#    #+#             */
/*   Updated: 2024/09/27 12:22:57 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (lst && del)
	{
		temp = *lst;
		while (temp)
		{
			next = temp->next;
			ft_lstdelone(temp, del);
			temp = next;
		}
		*lst = 0;
	}
}
