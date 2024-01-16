/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:27:25 by croussea          #+#    #+#             */
/*   Updated: 2023/11/30 16:32:12 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str < 0)
		return (NULL);
	while (i < len && s1[i] != '\0')
	{
		str[i] = *s1[i];
  		i++;
	}
	j = 0;
	while ((i + j + 1) < len && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (i < len)
		dest[i + j] = '\0';
	return (str); 
}
