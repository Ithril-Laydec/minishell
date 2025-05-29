#include "../minishell.h"

static int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || !*name)
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_envs(data_t *d)
{
	envs_t	*tmp;

	sort_envs(d);
	tmp = d->envs;
	while (tmp)
	{
		ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

static void	export_error(char *arg, data_t *d)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	d->exit_status = 1;
	return ;
}

static void	export_variable(char *arg, data_t *d)
{
	char	*name;
	char	*value;
	char	*equal_sign;

	if (!is_valid_identifier(arg))
		return (export_error(arg, d));
	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		name = ft_strdup(arg);
		*equal_sign = '=';
		value = equal_sign + 1;
	}
	else
	{
		name = ft_strdup(arg);
		value = "";
	}
	if (name)
	{
		ft_setenv(name, value, d);
		free(name);
	}
}

void	export(data_t *d)
{
	char	**cmd;
	int		i;

	cmd = d->sh_ln->cmd;
	if (!cmd[1])
	{
		print_export_envs(d);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		export_variable(cmd[i], d);
		i++;
	}
}
