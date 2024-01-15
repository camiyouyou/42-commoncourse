/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:52:38 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 15:28:45 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = dest;
	s = src;
	while (i < num)
	{
		*d++ = *s++;
		i++;
	}
	return (dest);
}
