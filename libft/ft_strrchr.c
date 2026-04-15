/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:00:39 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/20 18:15:22 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	int				len;

	len = 0;
	a = (unsigned char)c;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == a)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;

	char * str = "Hello World";
	c = 'H';
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str,c));
}
*/
