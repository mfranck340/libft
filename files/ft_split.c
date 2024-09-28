/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:04:17 by ffierro-          #+#    #+#             */
/*   Updated: 2024/09/26 22:09:17 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	save_memory(char const *s, char c, char **strs, int j)
{
	int	k;

	k = 0;
	while (s[k] != '\0' && !(s[k] == c))
		k++;
	strs[j] = (char *) malloc(sizeof(char) * (k + 1));
	if (!strs[j])
	{
		while (j >= 0)
		{
			free(strs[j]);
			j--;
		}
		free(strs);
		return (0);
	}
	strs[j][k] = '\0';
	return (1);
}

static char	**split_strs(char const *s, char c, char **strs)
{
	int	j;
	int	k;

	j = 0;
	while (*s)
	{
		if (!(*s == c))
		{
			if (!save_memory(s, c, strs, j))
				return (0);
			k = 0;
			while (*s && !(*s == c))
			{
				strs[j][k] = *s++;
				k++;
			}
			j++;
		}
		else
			s++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;

	if (!s)
		return (0);
	size = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (0);
	strs[size] = 0;
	return (split_strs(s, c, strs));
}
