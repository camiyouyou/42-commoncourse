/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:22:06 by croussea          #+#    #+#             */
/*   Updated: 2023/11/23 15:12:02 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;
    const unsigned char *u1;
    const unsigned char *u2;

	i = 0;
    u1 = s1;
    u2 = s2;
	if (!n)
	{
		return (0);
	}
	while (i < n && u1[i] == u2[i])
	{
		i++;
	}
	if (i < n)
	{
		return (u1[i] - u2[i]);
	}
	else
	{
		return (0);
	}
}
