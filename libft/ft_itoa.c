/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:57:29 by croussea          #+#    #+#             */
/*   Updated: 2024/01/19 13:19:00 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	count_char(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		digits;

	digits = count_char(n);
	new = (char *)malloc(sizeof(char) * (digits + 1));
	if (new == NULL)
		return (NULL);
	new[digits] = '\0';
	if (n == 0)
	{
		new[0] = '0';
	}
	else if (n < 0)
	{
		new[0] = 45;
	}
	while (n)
	{
		if (n < 0)
			new[--digits] = (~(n % 10) + 1) + 48;
		else
			new[--digits] = (n % 10) + 48;
		n /= 10;
	}
	return (new);
}
