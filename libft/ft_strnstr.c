/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:06:05 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/20 18:07:00 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;
	size_t			j;

	i = 0;
	s1 = (unsigned char *)big;
	s2 = (unsigned char *)little;
	if (*s2 == '\0')
		return ((char *)big);
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
