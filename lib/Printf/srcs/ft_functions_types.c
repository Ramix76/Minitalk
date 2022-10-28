/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:42:24 by framos-p          #+#    #+#             */
/*   Updated: 2022/07/15 11:12:52 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(int c)
{
	int	len;

	if (ft_putchar(c) != 1)
		return (-1);
	len = 1;
	return (len);
}

int	ft_print_string(char *string)
{
	int		len;

	len = 0;
	if (string == NULL)
	{	
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (string[len] != '\0')
	{	
		if (ft_putchar(string[len]) == -1)
			return (-1);
		len++;
	}	
	return (len);
}

int	ft_print_number(int c)
{
	char	*num;
	int		len;

	num = ft_itoa(c);
	if (!num)
		return (-1);
	len = ft_print_string(num);
	free(num);
	return (len);
}

int	ft_print_unsign(unsigned int n)
{
	char	*num;
	int		len;

	if (n == 0)
	{
		if (ft_putchar('0') != 1)
			return (-1);
		return (1);
	}
	num = ft_unsign_itoa(n);
	if (!num)
		return (-1);
	len = ft_print_string(num);
	free(num);
	return (len);
}

int	ft_print_hexa(unsigned long long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 16;
	}
	return (size);
}
