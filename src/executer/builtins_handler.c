#include "../minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin(data_t *d)
{
	if (!d->sh_ln || !d->sh_ln->cmd || !d->sh_ln->cmd[0])
		return (1);
	d->exit_status = 0;
	if (strcmp(d->sh_ln->cmd[0], "echo") == 0)
	{
		echo(d->sh_ln->cmd);
		return (d->exit_status);
	}
	else if (strcmp(d->sh_ln->cmd[0], "cd") == 0)
		cd(d);
	else if (strcmp(d->sh_ln->cmd[0], "pwd") == 0)
		pwd();
	else if (strcmp(d->sh_ln->cmd[0], "export") == 0)
		export(d);
	else if (strcmp(d->sh_ln->cmd[0], "unset") == 0)
		unset(d);
	else if (strcmp(d->sh_ln->cmd[0], "env") == 0)
		env(d);
	else if (strcmp(d->sh_ln->cmd[0], "exit") == 0)
		exit_shell(d);
	else
		return (127);
	return (d->exit_status);
}
