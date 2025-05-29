/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:46:27 by aternero          #+#    #+#             */
/*   Updated: 2025/05/29 23:44:06 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing_count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	inside_word;
	int	quote;

	i = 0;
	words = 0;
	inside_word = 0;
	quote = 0;
	while (s[i])
	{
		quote = flag_calculator((char *)s, i, quote);
		if ((s[i] != c || quote != 0) && !inside_word)
		{
			words++;
			inside_word = 1;
		}
		else if (s[i] == c && quote == 0)
			inside_word = 0;
		i++;
	}
	return (words);
}

static size_t	parsing_count_word_size(char const *s, char c, size_t start)
{
	size_t	letters;
	int		quote;

	letters = 0;
	quote = 0;
	while (s[start + letters])
	{
		quote = flag_calculator((char *)s, start + letters, quote);
		if (s[start + letters] == c && quote == 0)
			break;
		letters++;
	}
	return (letters);
}

static char	**parsing_splited_split(const char *s, char **array, char c)
{
	int	i;
	int	w;
	int	inside_word;
	int	quote;

	i = 0;
	w = 0;
	inside_word = 0;
	quote = 0;
	while (s[i])
	{
		quote = flag_calculator((char *)s, i, quote);
		if ((s[i] != c || quote != 0) && !inside_word)
		{
			inside_word = 1;
			array[w] = ft_substr(s, i, parsing_count_word_size(s, c, i));
			if (!array[w])
			{
				array_free(array);
				return (NULL);
			}
			w++;
		}
		else if (s[i] == c && quote == 0)
			inside_word = 0;
		i++;
	}
	return (array);
}

char	**parsing_split(char const *s, char c)
{
	char	**array;
	char	**ret;
	int		word_count;
	int		index;
	char	*trimmed;

	word_count = parsing_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!parsing_splited_split(s, array, c))
	{
		array_free(array);
		return (NULL);
	}
	array[word_count] = NULL;
	index = 0;
	while (array[index])
		index++;
	ret = malloc(sizeof(char *) * (index + 1));
	if (!ret)
	{
		array_free(array);
		return (NULL);
	}
	ret[index] = NULL;
	index = 0;
	while (array[index])
	{
		trimmed = ft_strtrim(array[index], " ");
		if (trimmed)
		{
			ret[index] = ft_strdup(trimmed);
			free(trimmed);
		}
		else
			ret[index] = ft_strdup("");
		if (!ret[index])
		{
			int i = 0;
			while (i < index)
				free(ret[i++]);
			free(ret);
			array_free(array);
			return (NULL);
		}
		index++;
	}
	array_free(array);
	return (ret);
}
