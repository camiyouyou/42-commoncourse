/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:53:50 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 11:56:06 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest == src)
	{
		return (dest);
	}
	if (s < d)
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
		return (dest);
	}
	while (len--)
	{
		*d++ = *s++;
	}
	return (dest);
}
