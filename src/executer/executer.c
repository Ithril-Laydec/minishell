#include "../minishell.h"

static void	count_commands(data_t *d)
{
	shell_line_t	*temp;

	d->pipeline.cmd_count = 0;
	temp = d->sh_ln;
	while (temp)
	{
		d->pipeline.cmd_count++;
		temp = temp->next;
	}
}

void	executer(data_t *d)
{
	if (!d->sh_ln || !d->sh_ln->cmd || !d->sh_ln->cmd[0])
		return ;
	count_commands(d);
	if (handle_single_parent_buildin(d) == 1)
		return ;
	d->pipeline.pids = malloc(d->pipeline.cmd_count * sizeof(pid_t));
	if (!d->pipeline.pids)
		custom_exit(d, "malloc pids failed", EXIT_FAILURE);
	d->exit_status = 0;
	g_signal = S_CMD;
	execute_pipeline(d);
	wait_for_children(d);
	g_signal = S_BASE;
	free(d->pipeline.pids);
}
