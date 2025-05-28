/*
#include "../minishell.h"

void	free_double_char(char **str)
{
	int	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		free(str[index]);
		str[index] = NULL;
	}
	free(str);
	str = NULL;
}
 */