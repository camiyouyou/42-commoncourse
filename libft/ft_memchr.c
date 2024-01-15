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

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s)[i] != c)
	{
		i++;
	}
	if (i < n && ((unsigned char *)s)[i] == c)
		return ((void *)((unsigned char *)s + i));
	else
		return (NULL);
}
