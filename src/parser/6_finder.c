
#include "../minishell.h"

int	flag_calculator(char *line, int index, int quote)
{
	if (line[index] == 34 && quote == 0)
		return (1);
	else if (line[index] == 34 && quote == 1)
		return (0);
	else if (line[index] == 39 && quote == 0)
		return (2);
	else if (line[index] == 39 && quote == 2)
		return (0);
	return (quote);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
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

int	is_there_dollars(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == 36)
			return (1);
		index++;
	}
	return (0);
}

int	is_there_quotes(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == 34)
			return (2);
		else if (str[index] == 39)
			return (1);
		index++;
	}
	return (0);
}
