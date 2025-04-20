
#include "../minishell.h"
#include "parser.h"

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

char	*ft_strndup(const char *str, size_t init)
{
	char	*dup;
	size_t	end;
	size_t	index;

	end = ft_strlen(str) - 1;
	while (str[end])
	{
		if (is_space(str[end]) == 0)
			break ;
		end--;
	}
	dup = malloc((end - init) + 1);
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
