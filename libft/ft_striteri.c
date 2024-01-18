void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;
    
    i = 0;
    if (s == NULL || f == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        f(i, s[i]);
        i++;
    }
}


