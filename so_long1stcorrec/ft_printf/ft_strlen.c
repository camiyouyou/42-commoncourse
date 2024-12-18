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

unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
