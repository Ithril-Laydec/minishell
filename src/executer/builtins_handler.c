#include "../minishell.h"

bool	is_builtin(const char *cmd)
{
	if (!cmd)
		return (false);
	if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}

bool	is_parent_builtin(const char *cmd)
{
	if (!cmd)
		return (false);
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}

int	execute_builtin(shell_line_t *cmd_node, data_t *d)
{
	char	**cmd;

	if (!cmd_node || !cmd_node->cmd || !cmd_node->cmd[0])
		return (1);

	cmd = cmd_node->cmd;

	if (strcmp(cmd[0], "echo") == 0)
		echo(cmd, d);
	else if (strcmp(cmd[0], "cd") == 0)
		cd(cmd, d);
	else if (strcmp(cmd[0], "pwd") == 0)
		pwd(d);
	else if (strcmp(cmd[0], "export") == 0)
		export(cmd, d);
	else if (strcmp(cmd[0], "unset") == 0)
		unset(cmd, d);
	else if (strcmp(cmd[0], "env") == 0)
		env(d);
	else if (strcmp(cmd[0], "exit") == 0)
		exit_shell(d);
	else
		return (127);

	return (0);
}
