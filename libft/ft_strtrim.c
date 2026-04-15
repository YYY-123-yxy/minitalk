/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:18:19 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/20 18:18:31 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findchar(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		e;
	int		i;
	char	*str;

	c = 0;
	while (s1[c] && findchar(s1[c], set))
		c++;
	e = ft_strlen(s1);
	while (e > c && findchar(s1[e - 1], set))
		e--;
	str = malloc(e - c + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (c < e)
		str[i++] = s1[c++];
	str[i] = '\0';
	return (str);
}
