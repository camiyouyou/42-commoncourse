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

int	*ft_strchr(const char *str, int c)
{

	while (*str != '\0' && *str != c)
	{
		str++;
	}
	if (*str == c)
		return ((char*)str);
	else
		return (NULL);
}	
