/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:14:35 by ffierro-          #+#    #+#             */
/*   Updated: 2024/09/25 01:14:39 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0 && s[i] != c)
			return (0);
		i--;
	}
	return ((char *) &s[i]);
}
