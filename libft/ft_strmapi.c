char    ft_striteri(char const *s, void (*f)(unsigned int, char))
{
    int i;
    char    *new;
    
    i = 0;
    new = (char)malloc(sizeof(char)*(ft_strlen(s) + 1))
    if (s == NULL)
        return (NULL);
    if (f == NULL)
    {
        ft_strlcopy(new, s, ft_strlen(s) + 1)
        return (new)
    }
    while (s[i] != '\0')
    {
        new[i] == f(i, s[i]);
        i++;
    }
    new[i] = '\0';
    return (new);
}


