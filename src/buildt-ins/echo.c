#include "../minishell.h"

void	echo(char **cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (cmd[1] && ft_strcmp(cmd[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_printf("%s", cmd[i]);
		if (cmd[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!n_flag)
		ft_printf("\n");
}
