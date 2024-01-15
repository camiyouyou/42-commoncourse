void *ft_memcpy(void *dest, const void *src, unsigned int num)
{
	unsigned char *d;
	const unsigned char *s;
	unsigned int i;

	i = 0;
	d = dest;
	s = src;
	while (i < num)
	{
		*d++ = *s++;
		i++;
	}
	return (dest);
}