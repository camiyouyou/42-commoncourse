/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:20 by croussea          #+#    #+#             */
/*   Updated: 2024/01/15 15:29:05 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		*p = (unsigned char)value;
		p++;
		i++;
	}
	return (ptr);
}
