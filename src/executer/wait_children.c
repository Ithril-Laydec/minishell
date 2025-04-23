#include "../minishell.h"

void	wait_for_children(int num_cmds, pid_t *pids, data_t *d)
{
	int	j;
	int	status;

	j = 0;
	while (j < num_cmds)
	{
		if (waitpid(pids[j], &status, 0) == -1)
			ft_printf("minishell: waitpid: %s\n", strerror(errno));
		if (j == num_cmds - 1)
		{
			if (WIFEXITED(status))
				d->exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				d->exit_status = 128 + WTERMSIG(status);
		}
		j++;
	}
}
