#include "../minishell.h"

void	executer(shell_line_t *shell_line)
{


	while (shell_line)
	{
		int	len;
		len = ft_strlen(shell_line->line);
		if (ft_strlen == 0)
		{
			shell_line = shell_line->next;
			continue ;
		}
		execve(shell_line->cmd[0], shell_line->cmd, NULL);
		shell_line = shell_line->next;
	}
}