#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void *ft_calloc(size_t size, size_t count)
{
    void *rtn;
    rtn = malloc(size * count);
    if (!rtn)
        return (NULL);
    ft_bzero(rtn, size * count);
    return (rtn);
}

