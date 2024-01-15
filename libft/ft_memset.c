void *ft_memset(void *ptr, int value, unsigned int num)
{
	unsigned char *p;
	unsigned int i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		*p = (unsigned char)value;
		p++;
		i++;
	}
	return (ptr);
}