#include "../minishell.h"


void	executer(data_t *d)
{
	int				num_cmds;
	pid_t			*pids;
	shell_line_t	*temp;

	if (!d->sh_ln || !d->sh_ln->cmd || !d->sh_ln->cmd[0])
		return;
	num_cmds = 0;
	temp = d->sh_ln;
	while (temp)
	{
		num_cmds++;
		temp = temp->next;
	}
	if (handle_single_parent_builtin(d, num_cmds))
		return;
	pids = malloc(num_cmds * sizeof(pid_t));
	if (!pids)
		error(d, "malloc pids failed");
	d->exit_status = 0;
	execute_pipeline(d, num_cmds, pids);
	wait_for_children(num_cmds, pids, d);
	free(pids);
}

