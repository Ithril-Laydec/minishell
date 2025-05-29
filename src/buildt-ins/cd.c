#include "../minishell.h"

static void	handle_cd_home(data_t *d)
{
	char	*path;

	path = ft_getenv("HOME", d);
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		d->exit_status = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		d->exit_status = 1;
	}
}

static void	handle_cd_previous(data_t *d)
{
	char	*path;

	path = ft_getenv("OLDPWD", d);
	if (!path || chdir(path) == -1)
		custom_exit(d, "cd: OLDPWD not set or not accessible", EXIT_FAILURE);
}

static int	handle_cd_path(char *path, data_t *d)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		d->exit_status = 1;
		return (0);
	}
	return (1);
}

static void	process_cd_args(data_t *d)
{
	char	**cmd;

	cmd = d->sh_ln->cmd;
	if (!cmd[1])
	{
		handle_cd_home(d);
		if (d->exit_status != 0)
			return ;
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		handle_cd_previous(d);
	else if (!handle_cd_path(cmd[1], d))
		return ;
	update_pwd_vars(d);
}

void	cd(data_t *d)
{
	char	**cmd;

	cmd = d->sh_ln->cmd;
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		d->exit_status = 1;
		return ;
	}
	process_cd_args(d);
}
