int ft_printf(const char *s, ...)
{
    int i;
    va_list ap;

    va_start(ap, s);
    i = 0;
    while (s)
    {
        if (*s == '%')
        {
            i++;
            if (*s == c)
            {
                ft_putchar_ap(va_arg(s, ap));
            }
        }
        ft_putchar(s[i]);
    }
    va_end(ap, s);
    
    // si le flag est c, utiliser ft_putchar
    //si le flag est s, putstring
    //si le flag est p --> custom fonction pour hexadecimal
    //si le flag est d, putnbr
    //si i le flag est i, putnbr
    //si le le flag est u, faire iun putnbr juste pour positifs
    // pour x et X custom fonction hexadecimale
    //%% --> ft_putchar %
    
}
