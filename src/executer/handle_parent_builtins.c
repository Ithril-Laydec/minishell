#include "../minishell.h"

static int	is_parent_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	handle_single_parent_buildin(data_t *d)
{
	if (d->pipeline.cmd_count == 1 && is_parent_builtin(d->sh_ln->cmd[0]))
	{
		d->exit_status = execute_builtin(d);
		return (1);
	}
	return (0);
}
