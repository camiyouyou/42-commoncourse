/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:28:46 by croussea          #+#    #+#             */
/*   Updated: 2024/03/16 17:10:04 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ap(int n, int base)
{
	int		i;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_ap('-');
		return (ft_putnbr_ap(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar_ap(symbols[n]));
	else
	{
		i = ft_putnbr_ap((n / base), base);
		return (i + ft_putnbr_ap((n % base), base));
	}
}

int	ft_putstr_ap(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar_ap(s[i]);
		i++;
	}
	return (i);
}

int	ft_putchar_ap(int c)
{
	return (write(1, &c, 1));
}

int	ft_hexa(unsigned long n, char format)
{
	char			*base;
	unsigned int	num;
	int				i;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)n;
	if (num >= 16)
		i += ft_hexa(num / 16, format);
	i += ft_putchar_ap(*(base + num % 16));
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar_ap(*(base + (n % 10)));
	return (len);
}
