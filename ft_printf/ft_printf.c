/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:33:56 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 20:21:45 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
			i += ft_format(*(++format), args);
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (i);
}
