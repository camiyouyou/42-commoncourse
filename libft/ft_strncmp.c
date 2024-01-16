/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:22:06 by croussea          #+#    #+#             */
/*   Updated: 2023/11/23 15:12:02 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
	{
		return (0);
	}
	while (i < n && (s1[i] && s2[i] && s1[i] == s2[i]))
	{
		i++;
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	else
	{
		return (0);
	}
}
