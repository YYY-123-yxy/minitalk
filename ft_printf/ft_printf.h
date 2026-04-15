/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:17:13 by ziyang            #+#    #+#             */
/*   Updated: 2025/12/26 17:45:58 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(char signe, va_list args);
int	ft_putchar(int c);
int	ft_puthexa_lower(unsigned int n);
int	ft_puthexa_upper(unsigned int n);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
int	ft_putunsigned_u(unsigned int n);

#endif
