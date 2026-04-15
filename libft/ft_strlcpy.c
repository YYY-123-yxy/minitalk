/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:48:07 by ziyang            #+#    #+#             */
/*   Updated: 2025/11/21 19:05:18 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	lensrc;
	size_t	i;

	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	if (n == 0)
		return (lensrc);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dest[20];
	char src[50] = "nihao,buxiangxuexile";
	size_t n = 6;

//	strlcpy(dest, src, n);
	ft_strlcpy(dest, src, n);
	printf("%s\n", dest);
}
*/
