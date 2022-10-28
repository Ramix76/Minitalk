/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:09:47 by framos-p          #+#    #+#             */
/*   Updated: 2022/10/21 13:14:56 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
	i++;
	}
	return (word);
}

char	**ft_liberar(char **result, int word)
{
	while (word > 0)
	{
		word--;
		free(result[word]);
	}
	free(result);
	return (0);
}

char	**ft_recortar(char const *s, char c, char **result)
{
	int	i;
	int	word;
	int	start;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			start = i;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[word] = ft_substr(s, start, (i - start) + 1);
			if (!result[word])
				return (ft_liberar(result, word));
			word++;
		}
		i++;
	}
	result[word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc((ft_n_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_recortar(s, c, result);
	return (result);
}
