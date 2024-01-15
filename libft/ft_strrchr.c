/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:59:43 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 14:00:11 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

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
		return ((char *)str);
	else
		return (NULL);
}
