#include "../minishell.h"

void	cd(char **cmd, data_t *d)
{
	char	*path;
	char	*oldpwd;
	char	*newpwd;

	if (!cmd[1])
	{
		path = ft_getenv("HOME", d);
		if (chdir(path) == -1)
			error(d, "cd");
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		oldpwd = ft_getenv("OLDPWD", d);
		if (chdir(oldpwd) == -1)
			error(d, "cd");
	}
	else
	{
		if (chdir(cmd[1]) == -1)
			error(d, "cd");
	}
	newpwd = getcwd(NULL, 0);
	setenv("OLDPWD", d->pwd, 1);
	setenv("PWD", newpwd, 1);
	free(newpwd);
}
