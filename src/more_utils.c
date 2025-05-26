
#include "parser.h"

int	flag_calculator(char *line, int index, int quote)
{
	if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 34 && quote == 0)
		return (1);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 34 && quote == 1)
		return (0);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 39 && quote == 0)
		return (2);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 39 && quote == 2)
		return (0);
	return (quote);
}

int	quotations_counter(char *str, char c)
{
	int	counter;
	int	index;

	counter = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] == c || (str[index - 1] && str[index - 1] != 92))
			counter++;
		index++;
	}
	return (counter);
}

int	commands_chars(char c)
{
	if (c == 34 || c == 36 || c == 39)
		return (1);
	return (0);
}

int	no_space_finder(char *str)
{
	int	index;

	index = 0;
	while (str[index] && is_space(str[index]) == 1)
		index++;
	return (index);
}

int	next_end(char *str, char c, int index)
{
	if (!c)
	{
		while (str[index] && is_space(str[index]) == 0)
			index++;
		return (index);
	}
	while (str[index] && str[index] != c)
		index++;
	return (index);
}

char	*ft_strnndup(const char *str, size_t init, size_t end)
{
	char	*dup;
	size_t	index;

	dup = malloc((end - init) + 2);
	if (!dup)
		return (NULL);
	index = 0;
	while (init <= end && str[init])
	{
		dup[index] = str[init];
		index++;
		init++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strndup(const char *str, size_t init)
{
	char	*dup;
	size_t	end;
	size_t	index;

	end = ft_strlen((char *)str) - 1;
	while (str[end])
	{
		if (is_space(str[end]) == 0)
			break ;
		end--;
	}
	dup = malloc((end - init) + 2);
	if (!dup)
		return (NULL);
	index = 0;
	while (init <= end && str[init])
	{
		dup[index] = str[init];
		index++;
		init++;
	}
	dup[index] = '\0';
	return (dup);
}

// ASCII values for the characters
// $: 36
// ': 39
// ": 34