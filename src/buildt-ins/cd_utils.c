#include "../minishell.h"

void	update_pwd_vars(data_t *d)
{
	char	*oldpwd;
	char	*newpwd;
	char	*need_free;

	oldpwd = ft_getenv("PWD", d);
	need_free = NULL;
	if (!oldpwd)
	{
		oldpwd = getcwd(NULL, 0);
		need_free = oldpwd;
	}
	newpwd = getcwd(NULL, 0);
	if (!newpwd)
	{
		if (need_free)
			free(need_free);
		custom_exit(d, "cd: error retrieving current directory", EXIT_FAILURE);
		return ;
	}
	ft_setenv("OLDPWD", oldpwd, d);
	ft_setenv("PWD", newpwd, d);
	free(newpwd);
	if (need_free)
		free(need_free);
}

