/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:38:13 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	inside_word;

	i = 0;
	words = 0;
	inside_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!inside_word)
				words++;
			inside_word = 1;
		}
		else
			inside_word = 0;
		i++;
	}
	return (words);
}

static size_t	count_word_size(char const *s, char c, size_t start)
{
	size_t	letters;

	letters = 0;
	while (s[start + letters] && s[start + letters] != c)
		letters++;
	return (letters);
}

static char	**splited_split(const char *s, char **array, char c)
{
	int	i;
	int	w;
	int	inside_word;

	i = 0;
	w = 0;
	inside_word = 0;
	while (s[i])
	{
		if (s[i] != c && !inside_word)
		{
			inside_word = 1;
			array[w] = ft_substr(s, i, count_word_size(s, c, i));
			if (!array[w])
			{
				free_array(array);
				return (NULL);
			}
			w++;
		}
		else if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	if (!splited_split(s, array, c))
		return (NULL);
	array[count_words(s, c)] = NULL;
	return (array);
}
