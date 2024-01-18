size_t count_char(int n)
{
    size_t i;
    
    i = 0;
    if (n < 0)
        i++;
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char    *new;
    size_t  digits;
    
    digits = count_char(n);
    if (n < 0)
    {
        n = -n;
        digits++;
        if (!(new = (char *)malloc(sizeof(char) * (digits + 1))))
                return (NULL);
        new[0] = '-';
    }
    else
    {
        if (!(new = (char *)malloc(sizeof(char) * (digits + 1))))
            return (NULL);
    }
    new[digits] = 0;
    while (digits--)
    {
        new[digits] = n % 10 + '0';
        n = n / 10;
    }
    return (new);
}

