/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:23:40 by framos-p          #+#    #+#             */
/*   Updated: 2022/06/22 10:41:24 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsign_len(unsigned int n)
{
	int	len;

	if (n == 0)
		len = 1;
	if (n > 0)
	{
		len = 0;
		while (n)
		{
			n = n / 10;
			len++;
		}
	}
	if (n < 0)
	{
		len = 1;
		while (n)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_unsign_itoa(unsigned int n)
{
	char	*result;
	int		len;

	len = ft_unsign_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n == 0)
		result[len - 1] = '0';
	if (n < 0)
	{
		*result = '-';
		n = -n;
	}
	while (n > 0 && len - 1 >= 0)
	{
		result[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (result);
}
