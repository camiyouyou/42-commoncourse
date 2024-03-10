#include "ft_printf.h"

int ft_print_ptr(size_t nbr)
{
    char *base;
    int i;
    
    base = "0123456789abcdef";
    i = 0;
    if (nbr >= 16)
        i += ft_print_ptr((nbr / 16));
    i += ft_putchar_ap(base[nbr % 16]);
    return (i);
}

int ft_ptr(size_t num)
{
    char *base;
    int i;
    int j;
    
    base = "0123456789abcdef";
    i = 0;
    j = 0;
    i += ft_putstr_ap("0x");
    j += ft_print_ptr(num);
    return (i + j);
}
