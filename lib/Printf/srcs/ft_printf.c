/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:34:28 by framos-p          #+#    #+#             */
/*   Updated: 2022/07/01 17:07:53 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format_type(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_print_string(va_arg(arg, char *)));
	if (c == '%')
		return (ft_print_char('%'));
	if (c == 'i' || c == 'd')
		return (ft_print_number(va_arg(arg, int)));
	if (c == 'u')
		return (ft_print_unsign(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (ft_hex_upper_nbr(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_hex_lower_nbr(va_arg(arg, unsigned int)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(arg, unsigned long long)));
	return (0);
}

int	ft_protect_functions(const char *str, va_list arg, int len)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res = ft_format_type(arg, str[i + 1]);
			if (res == -1)
				return (-1);
			len += res;
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			len++;
		}
	i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start (arg, str);
	len = ft_protect_functions(str, arg, len);
	va_end (arg);
	return (len);
}
