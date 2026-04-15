/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:00:02 by ziyang            #+#    #+#             */
/*   Updated: 2025/11/21 22:19:22 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	lendst = 0;
	lensrc = 0;
	i = 0;
	while (src[lensrc])
		lensrc++;
	while (dst[lendst] && lendst < siz)
		lendst++;
	if (lendst == siz)
		return (siz + lensrc);
	while (src[i] && lendst + 1 + i < siz)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char dest[50] = "nihaoma?";
	char src[20] = "wohenhao!";
	size_t siz = 50;
	strlcat(dest, src, siz);
	printf("%s\n",dest);
}
*/
