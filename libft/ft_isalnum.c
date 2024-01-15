/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:44:00 by croussea          #+#    #+#             */
/*   Updated: 2023/11/13 19:37:19 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
