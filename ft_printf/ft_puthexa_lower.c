/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:28:40 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 17:56:37 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_lower(unsigned int n)
{
	int				i;
	char			*base;
	unsigned long	nb;

	i = 0;
	nb = n;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_puthexa_lower(nb / 16);
	}
	write(1, base + (nb % 16), 1);
	i++;
	return (i);
}
