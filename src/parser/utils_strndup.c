
#include "../minishell.h"

char	*ft_strndup(const char *str, int init)
{
	char	*dup;
	int		end;
	int		index;

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
