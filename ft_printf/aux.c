
void    ft_putnbr_ap(int n, int base)
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

void    ft_putstr_ap(char *s, int fd)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

void    ft_putchar_ap(char c, int fd)
{
    if (ft_isascii(c))
        return write (1, &c, 1);
}

