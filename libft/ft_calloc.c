/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:44:03 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 15:26:49 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		*p = 0;
		p++;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t size, size_t count)
{
	void	*rtn;

	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, size * count);
	return (rtn);
}
