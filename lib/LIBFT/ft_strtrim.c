/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:01:03 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/21 13:14:12 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
			i++;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[j - 1]))
			j--;
	new = ft_substr(s1, i, j - i);
	return (new);
}
