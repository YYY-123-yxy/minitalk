/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:44:58 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 17:56:23 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa(unsigned long nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_puthexa(nb / 16);
	}
	write(1, base + (nb % 16), 1);
	i++;
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 2;
	i += ft_puthexa((unsigned long)ptr);
	return (i);
}
