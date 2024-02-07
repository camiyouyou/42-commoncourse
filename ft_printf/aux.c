
int    ft_putnbr_ap(int n, int base)
{
    int    i;
    char    *symbols;

    symbols = "0123456789abcdef"
    if (n < 0)
    {
        ft_putchar_ap('-');
        return ft_putnbr_ap(-n, base) + 1;
    }
    else if (n < base)
        return ft_putchar_ap(symbols[n]);
    else
    {
        i = ft_putnbr_ap((n / base), base);
        return i + ft_putnbr_ap((n % base), base);
    }
}

int    ft_putstr_ap(char *s)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    return (i);
}

int    ft_putchar_ap(char c)
{
    if (ft_isascii(c))
        return write (1, &c, 1);
}

int    ft_hexa(unsigned long n, char format)
{
    char    *base;
    unsigned int    num;
    int    i;
    unsigned int    base_len;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    i = 0;
    num = (unsigned int)n;
    base_len = ft_strlen(base);
    if (num > (base_len - 1))
        i += ft_hexa(num / base_len, format);
    i += ft_putchar_ap(*(base + num % base_len);
    return (i);
}

