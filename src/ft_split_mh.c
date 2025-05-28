/* #include "../minishell.h"

static void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

static int	count_words(char const *str, char c)
{
	int	index;
	int	words;
	int	in_word;
	int	in_quote[2];

	index = 0;
	words = 0;
	in_word = 0;
	in_quote[0] = 0;
	in_quote[1] = 0;
	while (str[index])
	{
		if (str[index] == '\'' && !in_quote[1])
			in_quote[0] = !in_quote[0];
		else if (str[index] == '\"' && !in_quote[0])
			in_quote[1] = !in_quote[1];
		
		if ((str[index] != c || in_quote[0] || in_quote[1]) && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (str[index] == c && !in_quote[0] && !in_quote[1])
			in_word = 0;
		index++;
	}
	return (words);
}

static size_t	word_length(char const *str, char c, size_t start)
{
	size_t	len;
	int		in_quote[2];

	len = 0;
	in_quote[0] = 0;
	in_quote[1] = 0;
	while (s[start + len])
	{
		// Actualiza estado de comillas
		if (str[start + len] == '\'' && !in_quote[1])
			in_quote[0] = !in_quote[0];
		else if (str[start + len] == '\"' && !in_quote[0])
			in_quote[1] = !in_quote[1];
		
		if (str[start + len] == c && !in_quote[0] && !in_quote[1])
			break;
		len++;
	}
	return (len);
}

static char	**split_with_quotes(const char *str, char **array, char c)
{
	int	index[2];
	int	in_word;
	int	in_quote[2];

	index[0] = 0;
	index[1] = 0;
	in_word = 0;
	in_quote[0] = 0;
	in_quote[1] = 0;
	while (str[index[0]])
	{
		// Actualiza estado de comillas
		if (str[index[0]] == '\'' && !in_quote[1])
			in_quote[0] = !in_quote[0];
		else if (str[index[0]] == '\"' && !in_quote[0])
			in_quote[1] = !in_quote[1];
		
		if ((str[index[0]] != c || in_quote[0] || in_quote[1]) && !in_word)
		{
			in_word = 1;
			array[index[0]] = ft_substr(str, index[0], word_length(str, c, index[0]));
			if (!array[index[1]++])
			{
				free_array(array);
				return (NULL);
			}
		}
		else if (str[index[0]] == c && !in_quote[0] && !in_quote[1])
			in_word = 0;
		index[0]++;
	}
	return (array);
}

char	**ft_split_quotes(char const *str, char c)
{
	char	**array;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!split_with_quotes(str, array, c))
		return (NULL);
	array[word_count] = NULL;
	return (array);
} */