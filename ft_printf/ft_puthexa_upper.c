/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:36:36 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 17:56:32 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_upper(unsigned int n)
{
	int				i;
	char			*base;
	unsigned long	nb;

	i = 0;
	nb = n;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_puthexa_upper(nb / 16);
	write(1, base + (nb % 16), 1);
	i++;
	return (i);
}
