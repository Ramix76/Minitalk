/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:00:16 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/21 13:15:15 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
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

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	valor;

	valor = n;
	len = ft_len(valor);
	result = ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (0);
	if (valor == 0)
		result[len - 1] = '0';
	if (valor < 0)
	{
		*result = '-';
		valor = -valor;
	}
	while (valor > 0 && len - 1 >= 0)
	{
		result[len - 1] = valor % 10 + '0';
		len--;
		valor = valor / 10;
	}
	return (result);
}
