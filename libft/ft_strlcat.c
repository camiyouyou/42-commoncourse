/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:24 by croussea          #+#    #+#             */
/*   Updated: 2023/11/20 19:09:02 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while ((i + j + 1) < size && src[j] != '\0')
	{
		dst[i + j] = src [j];
		j++;
	}
	if (i < size)
	{
		dst[i + j] = '\0';
	}
	while (src[j] != '\0')
	{
		j++;
	}
	return (i + j);
}
