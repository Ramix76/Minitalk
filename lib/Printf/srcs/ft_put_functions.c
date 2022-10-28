/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:28:16 by framos-p          #+#    #+#             */
/*   Updated: 2022/07/15 10:45:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

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
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
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
