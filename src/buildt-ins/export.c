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

static void	sort_envs(data_t *d)
{
	envs_t	*tmp;
	envs_t	*next;
	char	*temp_name;
	char	*temp_value;

	tmp = d->envs;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (ft_strcmp(tmp->name, next->name) > 0)
			{
				temp_name = tmp->name;
				temp_value = tmp->value;
				tmp->name = next->name;
				tmp->value = next->value;
				next->name = temp_name;
				next->value = temp_value;
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
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

void	export(char **cmd, data_t *d)
{
	int		i;
	char	*name;
	char	*value;
	char	*equal_sign;

	if (!cmd[1])
	{
		print_export_envs(d);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		if (!is_valid_identifier(cmd[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			d->exit_status = 1;
			i++;
			continue;
		}
		equal_sign = ft_strchr(cmd[i], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			name = ft_strdup(cmd[i]);
			*equal_sign = '=';
			value = equal_sign + 1;
		}
		else
		{
			name = ft_strdup(cmd[i]);
			value = "";
		}
		if (name)
		{
			ft_setenv(name, value, d);
			free(name);
		}
		i++;
	}
}
