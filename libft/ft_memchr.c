/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:47:24 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 11:49:32 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const char *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && str[i] != c)
	{
		i++;
	}
	if (i < len && str[i] == c)
		return ((void *)(unsigned char *)str + i);
	else
		return (NULL);
}
