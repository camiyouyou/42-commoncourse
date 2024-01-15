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

int	*ft_strrchr(const char *str, int c)
{
	int i;
	int j;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	j = 0;
	while ((*str != c) && (j < i))
	{
		str--;
		j++;
	}
	if (*str == c)
		return ((char*)str);
	else
		return (NULL);
}	
