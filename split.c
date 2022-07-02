/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:40:36 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/15 19:40:37 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_mystrlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (len >= strlen)
		len = strlen;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	if (start > strlen)
	{
		result[0] = '\0';
		return (result);
	}
	result = ft_mystrlcpy(result, &s[start], len);
	return (result);
}

int	num_of_words(const char *str, char charset)
{
	int				i;
	unsigned int	words;
	int				count;

	count = 0;
	i = 0;
	words = 0;
	while (str[i] != '\0' && charset == str[i])
		i++;
	while (str[i] != '\0')
	{
		if (charset != str[i] && count == 0)
		{
			words++;
			count = 1;
		}
		else if (charset == str[i])
			count = 0;
		i++;
	}
	return (words);
}

char	**do_stuff(const char *s, char c, char **array)
{
	int	i;
	int	j;
	int	word;
	int	len;

	i = 0;
	j = 0;
	word = 0;
	len = num_of_words(s, c);
	while (word < len && i <= (int)ft_strlen(s))
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j])
				j++;
			array[word] = ft_substr(s + i, 0, j);
			if (!array[word++])
				return (NULL);
		}
		i += j + 1;
	}
	array[word] = 0;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char			**array;

	if (!s)
		return (NULL);
	array = (char **)malloc((num_of_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (array);
	array = do_stuff(s, c, array);
	return (array);
}
