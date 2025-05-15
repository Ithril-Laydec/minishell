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
			custom_exit(d, "cd");
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		oldpwd = ft_getenv("OLDPWD", d);
		if (chdir(oldpwd) == -1)
			custom_exit(d, "cd");
	}
	else
	{
		if (chdir(cmd[1]) == -1)
			custom_exit(d, "cd");
	}
	newpwd = getcwd(NULL, 0);
	setenv("OLDPWD", oldpwd, 1);
	setenv("PWD", newpwd, 1);
	free(oldpwd);
	free(newpwd);
}
