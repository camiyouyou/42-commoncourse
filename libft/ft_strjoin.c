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

int	ft_totalen(int size, char **strs, char *sep)
{
	int	j;
	int	len;

	len = 0;
	j = 0;
	if (size == 0)
		return (0);
	while (j < size)
	{
		len = len + ft_strlen(strs[j++]);
	}
	len = len + (ft_strlen(sep) * (size - 1));
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		len;
	int		s;

	i = 0;
	s = 0;
	len = ft_totalen(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			str[s++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
				str[s++] = sep[j++];
		}
		i++;
	}
	str[s] = '\0';
	return (str);
}
