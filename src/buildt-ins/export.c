#include "../minishell.h"

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

	if (!cmd[1])
	{
		print_export_envs(d);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		name = ft_strndup(cmd[i], no_space_finder(cmd[i]));
		value = ft_strchr(cmd[i], '=');
		if (value)
			value++;
		else
			value = "";
		ft_setenv(name, value, d);
		free(name);
		i++;
	}
}
