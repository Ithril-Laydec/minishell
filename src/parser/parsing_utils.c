
#include "../minishell.h"
#include "../parser.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	words_counter(char *line)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (is_space(line[index]) == 1)
		index++;
	if (line[index] && is_space(line[index]) == 0)
		count++;
	while (line[index++])
	{
		if (is_space(line[index]) == 1
			&& (line[index + 1] && is_space(line[index + 1]) == 0))
			count++;
	}
	return (count);
}
