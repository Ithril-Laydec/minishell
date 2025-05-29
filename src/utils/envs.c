#include "../minishell.h"

char	*ft_getenv(char *name, data_t *d)
{
	envs_t	*tmp;
	tmp = d->envs;

	if (name == NULL || d == NULL || d->envs == NULL)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_setenv(char *name, char *value, data_t *d)
{
	envs_t	*tmp;
	envs_t	*new_env;

	if (name == NULL || value == NULL || d == NULL)
		return ;
	tmp = d->envs;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	new_env = salloc(sizeof(envs_t), d);
	new_env->name = ft_strdup(name);
	new_env->value = ft_strdup(value);
	tmp = d->envs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_env;
	new_env->next = NULL;
}

void	ft_unsetenv(char *name, data_t *d)
{
	envs_t	*tmp;
	envs_t	*prev;

	if (name == NULL || d == NULL)
		return ;
	tmp = d->envs;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				d->envs = tmp->next;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	sort_envs(data_t *d)
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
