#include "ft_printf.h"


int ft_ptrlen(uintptr_t n)
{
    int len;
    
    len = 0;
    while(n != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void    ft_ptr(uintptr_t n)
{
    if (num >= 16)
    {
        ft_ptr(n / 16);
        ft_ptr(n % 16);
    }
    else
    {
        if (n <= 9)
            ft_putchar_ap((num + '0'), 1);
        else
            ft_putchar_ap((num - 10 + 'a'), 1);
    }
}

int    ft_print_ptr(unsigned long long ptr)
{
    int    print_length;

    print_length = 0;
    print_length += write(1, "0x", 2);
    if (ptr == 0)
        print_length += write(1, "0", 1);
    else
    {
        ft_ptr(ptr);
        print_length += ft_ptr_len(ptr);
    }
    return (print_length);
}
