#include "../minishell.h"

void	unset(char **cmd, data_t *d)
{
	while(*cmd)
	{
		if (ft_getenv(*cmd, d))
		{
			ft_unsetenv(*cmd, d);
		}
		cmd++;
	}
}
