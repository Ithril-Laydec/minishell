
#include "../minishell.h"
#include "parser.h"

void	free_double_char(char **str)
{
	if (!str || !*str)
		return ;
	while (*str)
	{
		free(*str);
		str = NULL;
	}
	free(str);
}
