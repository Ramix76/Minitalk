/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:17:29 by framos-p          #+#    #+#             */
/*   Updated: 2022/07/06 10:40:05 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hex_upper_nbr(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789ABCDEF";
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
		if (ft_hex_upper_nbr(n / 16) == -1)
			return (-1);
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	len = ft_print_hexa(n);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_hex_lower_nbr(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
		if (ft_hex_lower_nbr(n / 16) == -1)
			return (-1);
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	len = ft_print_hexa(n);
	if (len == -1)
		return (-1);
	return (len);
}

void	ft_pointer(unsigned long long n)
{
	if (n >= 16)
	{
		ft_pointer(n / 16);
		ft_pointer(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	len += ft_putchar('0');
	if (len == -1)
		return (-1);
	len += ft_putchar('x');
	if (len == -1)
		return (-1);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_pointer(ptr);
		len += ft_print_hexa(ptr);
	}
	return (len);
}
