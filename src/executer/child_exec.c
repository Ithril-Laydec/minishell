#include "../minishell.h"

char	*find_cmd_path_in_exec(const char *cmd, data_t *d)
{
	char	*path_var;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_var = ft_getenv("PATH", d);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			free_double_char(paths);
			return (NULL);
		}
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
		{
			free_double_char(paths);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free_double_char(paths);
			return (full_path);
		}
		free(full_path);
	}
	free_double_char(paths);
	return (NULL);
}

void	execute_child_command(shell_line_t *cmd_node, data_t *d)
{
	char	*cmd_path;
	int		builtin_exit_code;

	if (is_builtin(cmd_node->cmd[0]))
	{
		builtin_exit_code = execute_builtin(cmd_node, d);
		// ft_printf("exit code %d\n", builtin_exit_code);
		exit(builtin_exit_code);
	}
	cmd_path = find_cmd_path_in_exec(cmd_node->cmd[0], d);
	if (!cmd_path)
	{
		ft_printf("minishell: %s: command not found\n", cmd_node->cmd[0]);

		exit(127);
	}
	if (execve(cmd_path, cmd_node->cmd, d->str_env) == -1)
	{
		ft_printf("minishell: %s: %s\n", cmd_path, strerror(errno));
		free(cmd_path);

		exit(126);
	}

	free(cmd_path);
	exit(EXIT_FAILURE);
}
