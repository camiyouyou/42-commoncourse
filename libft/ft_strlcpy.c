/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:24 by croussea          #+#    #+#             */
/*   Updated: 2023/11/20 19:09:02 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < size && dst[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
