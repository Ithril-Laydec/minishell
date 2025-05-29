#include "../minishell.h"

static int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || !*name)
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	unset(data_t *d)
{
	int		i;
	char	**cmd;

	cmd = d->sh_ln->cmd;
	i = 1;
	while (cmd[i])
	{
		if (!is_valid_identifier(cmd[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			d->exit_status = 1;
		}
		else if (ft_getenv(cmd[i], d))
			ft_unsetenv(cmd[i], d);
		i++;
	}
}
