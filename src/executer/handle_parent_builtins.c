#include "../minishell.h"

bool	handle_single_parent_builtin(data_t *d, int num_cmds)
{
	shell_line_t	*cmd_node;

	cmd_node = d->sh_ln;
	if (num_cmds == 1 && is_parent_builtin(cmd_node->cmd[0]))
	{

		d->exit_status = execute_builtin(cmd_node, d);
		return (true);
	}
	return (false);
}
