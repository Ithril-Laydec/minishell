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
			return array_free(paths);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return array_free(paths);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	array_free(paths);
	return (NULL);
}

static int	is_valid_command(char *cmd)
{
	if (!cmd || cmd[0] == '\0')
		return (0);
	return (1);
}

static int	handle_file_execution(char *cmd_path, char **args)
{
	struct stat	file_stat;

	if (access(cmd_path, F_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
	if (stat(cmd_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		return (126);
	}
	if (access(cmd_path, X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (126);
	}
	return (0);
}

void	execute_child_command(shell_line_t *cmd_node, data_t *d)
{
	char	*cmd_path;
	int		builtin_exit_code;
	int		cmd_status;
	int		i;

	if (cmd_node->cmd[0] && ft_strcmp(cmd_node->cmd[0], "$") == 0)
	{
		ft_putstr_fd("minishell: $: command not found\n", 2);
		exit(127);
	}
	if (cmd_node->cmd[0] && cmd_node->cmd[0][0] == '\0' && cmd_node->cmd[1])
	{
		i = 0;
		while (cmd_node->cmd[i + 1])
		{
			cmd_node->cmd[i] = cmd_node->cmd[i + 1];
			i++;
		}
		cmd_node->cmd[i] = NULL;
	}
	if (!cmd_node->cmd[0] || !is_valid_command(cmd_node->cmd[0]))
	{
		exit(0);
	}
	if (is_builtin(cmd_node->cmd[0]))
	{
		builtin_exit_code = execute_builtin(cmd_node, d);
		exit(builtin_exit_code);
	}
	cmd_path = find_cmd_path_in_exec(cmd_node->cmd[0], d);
	if (!cmd_path)
	{
		if (ft_strchr(cmd_node->cmd[0], '/'))
		{
			cmd_status = handle_file_execution(cmd_node->cmd[0], cmd_node->cmd);
			exit(cmd_status);
		}
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_node->cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	cmd_status = handle_file_execution(cmd_path, cmd_node->cmd);
	if (cmd_status != 0)
	{
		free(cmd_path);
		exit(cmd_status);
	}
	if (execve(cmd_path, cmd_node->cmd, d->str_env) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(cmd_path);
		exit(126);
	}
	free(cmd_path);
	exit(EXIT_FAILURE);
}
