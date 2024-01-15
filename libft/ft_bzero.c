void *ft_bzero(void *ptr, unsigned int num)
{
	unsigned char *p;
	unsigned int i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		*p = 0;
		p++;
		i++;
	}
	return (ptr);
}