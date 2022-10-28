/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:26:38 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/21 13:12:26 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s1)[i] != (((unsigned char *)s2)[i]))
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
	i++;
	n--;
	}
	return (0);
}
