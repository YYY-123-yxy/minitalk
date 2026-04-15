/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:40:59 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/20 18:12:07 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *)&s[i]);
	return (NULL);
}
