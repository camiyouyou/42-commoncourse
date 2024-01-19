/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:48 by croussea          #+#    #+#             */
/*   Updated: 2024/01/19 00:13:34 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	len;

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
	ft_strlcpy(newstr, s1 + i, (len - i) + 2);
	return (newstr);
}
