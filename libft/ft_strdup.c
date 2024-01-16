/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:10 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 13:38:50 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	dest = 0;
	i = 0;
	len = ft_strlen((char *) s1);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	else
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
