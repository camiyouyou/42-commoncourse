/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:38:59 by croussea          #+#    #+#             */
/*   Updated: 2024/03/16 17:37:28 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar_ap(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr_ap(va_arg(ap, char *));
	else if (s == 'x' || s == 'X')
		count += ft_hexa(va_arg(ap, unsigned long), s);
	else if (s == 'p')
		count += ft_ptr(va_arg(ap, unsigned long long));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr_ap(va_arg(ap, int), 10);
	else if (s == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned long));
	else if (s == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	if (!s)
	{
		return (0);
	}
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += print_format(*s, ap);
		}
		else
		{
			count += write(STDOUT_FILENO, s, 1);
		}
		s++;
	}
	va_end(ap);
	return (count);
}
