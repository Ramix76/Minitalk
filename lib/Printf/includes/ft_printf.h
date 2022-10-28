/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:29:19 by framos-p          #+#    #+#             */
/*   Updated: 2022/07/07 10:49:32 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_protect_functions(const char *str, va_list arg, int len);
void	ft_pointer(unsigned long long n);
int		ft_print_pointer(unsigned long long ptr);
int		ft_print_hexa(unsigned long long n);
int		ft_hex_lower_nbr(unsigned int n);
int		ft_hex_upper_nbr(unsigned int n);
int		ft_print_unsign(unsigned int n);
int		ft_unsign_len(unsigned int n);
char	*ft_unsign_itoa(unsigned int n);
int		ft_len(int n);
char	*ft_itoa(int n);
int		ft_print_number(int c);
int		ft_print_percent(int c);
int		ft_putchar(int c);
int		ft_print_char(int c);
int		ft_printf(const char *str, ...);
int		ft_format_type(va_list arg, char c);
int		ft_print_string(char *string);

#endif
