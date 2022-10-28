/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:40:40 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/21 13:14:34 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptrsub;
	size_t			slen;

	slen = ft_strlen(s);
	if (slen == 0 || start > slen)
	{
		ptrsub = ft_strdup("");
		return (ptrsub);
	}
	else if (len > slen - start)
			len = slen - start;
	ptrsub = malloc((len + 1) * (sizeof(char)));
	if (!ptrsub)
		return (0);
	ft_strlcpy(ptrsub, (char *)(s + start), (len + 1));
	return (ptrsub);
}
