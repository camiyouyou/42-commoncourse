/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:06:50 by croussea          #+#    #+#             */
/*   Updated: 2024/03/16 17:09:56 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(size_t nbr)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (nbr >= 16)
		i += ft_print_ptr((nbr / 16));
	i += ft_putchar_ap(base[nbr % 16]);
	return (i);
}

int	ft_ptr(size_t num)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i += ft_putstr_ap("0x");
	j += ft_print_ptr(num);
	return (i + j);
}
