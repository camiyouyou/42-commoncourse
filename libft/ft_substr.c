#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while ((i - start) < len)
	{
        str[i] = s[i];
        i++;
	}
	str[s] = '\0';
	return (str);
}
