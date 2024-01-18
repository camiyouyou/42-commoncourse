void    ft_putchar_fd(char c, int fd)
{
    if (ft_isascii(c))
        write (fd, &c, 1);
}

void    ft_putendl(char *s, int fd)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i]);
        i++;
    }
    ft_putchar_fd('\n');
}


