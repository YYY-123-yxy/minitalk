/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:39:55 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 17:31:48 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_u(unsigned int n)
{
	int		i;
	char	c;

	i = 0;
	if (n >= 10)
	{
		i += ft_putunsigned_u(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
