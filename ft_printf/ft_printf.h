#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

//printf

int    ft_putnbr_ap(int n, int base);
int    ft_putstr_ap(char *s);
int    ft_putchar_ap(int c);
int    ft_hexa(unsigned long n, char format);
int    ft_putunsigned(unsigned long n);
int    ft_printf(const char *s, ...);
unsigned long    ft_strlen(char *s);

#endif

