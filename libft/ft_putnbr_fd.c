void    ft_putchar_fd(char c, int fd)
{
    if (ft_isascii(c))
        write (fd, &c, 1);
}

void    ft_putnbr(int n, int fd)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-');
        n = -n;
    }
    if (nb > 9)
    {
        ft_putnbr_fd(n / 10);
        ft_putchar_fd((n % 10) + '0');
    }
    else
    {
        ft_putchar_fd(n + '0');
    }
}
