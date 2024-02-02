/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:48 by croussea          #+#    #+#             */
/*   Updated: 2024/01/31 13:38:05 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && ft_strchrr(set, s1[i]))
		i++;
	while (len > i && ft_strchrr(set, s1[len - 1]))
		len--;
	if (i > len)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (len - i + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < len)
		newstr[j++] = s1[i++];
	newstr[j] = '\0';
	return (newstr);
}
