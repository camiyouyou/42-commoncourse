/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:54:26 by croussea          #+#    #+#             */
/*   Updated: 2023/11/20 18:07:01 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const char *str, int c, unsigned int len)
{
    int i;
    
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
