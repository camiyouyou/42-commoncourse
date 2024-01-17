#include <stdlib.h>
#include "libft.h"

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
    size_t  len;

	i = 0;
    len = ft_strlen(s1);
    if (s1 == NULL || set == NULL)
        return (NULL);
    while (s1[i] && ft_strchr(set, s1[i]))
        i++;
    while (len > 0 && ft_strchr (set, s1[len]))
        len--;
    if (i > len)
        return (ft_strdup(""));
    newstr = (char *)malloc(sizeof(char) * (len - i + 2));
    if (newstr == NULL)
        return (NULL);
    ft_strlcpy(newstr, s1 + i, (len - i) + 1);
	return (newstr);
}
