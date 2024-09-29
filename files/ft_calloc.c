/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:07:51 by ffierro-          #+#    #+#             */
/*   Updated: 2024/09/29 12:17:38 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n_bytes;

	n_bytes = nmemb * size;
	if (size && (n_bytes / size) != nmemb)
		return (0);
	ptr = malloc(n_bytes);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n_bytes);
	return (ptr);
}
