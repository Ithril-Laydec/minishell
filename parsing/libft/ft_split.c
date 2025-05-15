/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:30 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

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
	int		yndex;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	if (!splited_split(s, array, c))
		return (NULL);
	array[count_words(s, c)] = NULL;
	yndex = 0;
	while (array[yndex])
	{
		array[yndex] = ft_strtrim(array[yndex], " ");
		yndex++;
	}
	return (array);
}
