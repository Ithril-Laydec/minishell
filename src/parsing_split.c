#include "parser.h"

static void	parsing_free_array(char **array)
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

static int	parsing_count_words(char const *s, char c)
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
				parsing_free_array(array);
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
	int		word_count;

	word_count = parsing_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!parsing_splited_split(s, array, c))
		return (NULL);
	array[word_count] = NULL;
	return (array);
}
