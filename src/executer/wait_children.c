#include "../minishell.h"

void	wait_for_children(data_t *d)
{
	int	status;
	int	i;

	i = 0;
	while (i < d->pipeline.cmd_count)
	{
		waitpid(d->pipeline.pids[i], &status, 0);
		if (g_signal == S_SIGINT_CMD)
			d->exit_status = 130;
		else if (WIFEXITED(status))
			d->exit_status = WEXITSTATUS(status);
		i++;
	}
	g_signal = S_BASE;
}
