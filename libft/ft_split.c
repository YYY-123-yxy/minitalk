/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:10:28 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/20 20:10:29 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (*s)
	{
		if (*s != c && index == 0)
		{
			index = 1;
			i++;
		}
		else if (*s == c)
			index = 0;
		s++;
	}
	return (i);
}

static char	**free_split(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

static char	*ft_motsndup(char const *s, int n)
{
	char	*str;
	int		i;

	str = (char *)malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		j = 0;
		while (s[j] && (s[j] != c))
			j++;
		tab[i] = ft_motsndup(s, j);
		if (!tab[i])
			return (free_split(tab, i));
		i++;
		s += j;
	}
	tab[i] = NULL;
	return (tab);
}
