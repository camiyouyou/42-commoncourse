int ft_printf(const char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    if (*s == '%')
{
    s++; // Passer au caractère suivant après '%'
    if (*s == 'c')
        ft_putchar_ap(va_arg(ap, int));
    else if (*s == 's')
        ft_putstr_ap(va_arg(ap, char *));
    else if (*s == 'x' || *s == 'X' || *s == 'p')
        ft_hexa(va_arg(ap, unsigned long), *s);
    else if (*s == 'd' || *s == 'i')
        ft_putnbr_ap(va_arg(ap, int), 10); // '10' pour base décimale
    else if (*s == 'u')
        ft_putunsigned(va_arg(ap, unsigned long));
}
    va_end(ap, s);
}
