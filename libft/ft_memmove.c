void *ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;
    
	d = dest;
	s = src;
    if (dest == src)
    {
        return (dest);
    }
    if (s < d)
    {
        while (len--)
        {
            *(d + len) = *(s + len);
        }
        return (dest);
    }
    while (len--)
    {
        *d++ = *s++;
    }
	return (dest);
}
