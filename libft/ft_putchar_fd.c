void    ft_putchar_fd(char c, int fd)
{
    if (ft_isascii(c))
        write (fd, &c, 1);
}


