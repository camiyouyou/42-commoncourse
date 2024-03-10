#include "ft_printf.h"


int print_format(char s, va_list ap)
{
    int count;
    
    count = 0;
    if (s == 'c')
        count += ft_putchar_ap(va_arg(ap, int));
    else if (s == 's')
        count += ft_putstr_ap(va_arg(ap, char *));
    else if (s == 'x' || s == 'X')
        count += ft_hexa(va_arg(ap, unsigned long), s);
    else if(s == 'p')
        count += ft_ptr(va_arg(ap, unsigned long long));
    else if (s == 'd' || s == 'i')
        count += ft_putnbr_ap(va_arg(ap, int), 10); // '10' pour base décimale
    else if (s == 'u')
        count += ft_putunsigned(va_arg(ap, unsigned long));
    else if (s == '%')
        count += write (1, "%", 1);
    return (count);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    int count;
    
    va_start(ap, s);
    count = 0;
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

/* int main ()
{
    ft_printf(" %c %c %c ", '2', '1', 0);
} */
