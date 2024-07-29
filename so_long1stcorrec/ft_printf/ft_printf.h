/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:20:01 by croussea          #+#    #+#             */
/*   Updated: 2024/03/16 17:22:29 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

//printf

int	ft_putnbr_ap(int n, int base);
int	ft_putstr_ap(char *s);
int	ft_putchar_ap(int c);
int	ft_hexa(unsigned long n, char format);
int	ft_putunsigned(unsigned int n);
int	ft_printf(const char *s, ...);
int	ft_ptr(size_t num);
int	ft_print_ptr(size_t nbr);
int	print_format(char s, va_list ap);

#endif
