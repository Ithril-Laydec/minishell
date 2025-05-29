#include "../minishell.h"

void	env(data_t *d)
{
	envs_t	*tmp;

	tmp = d->envs;
	while (tmp)
	{
		if (tmp->name != NULL && tmp->value != NULL)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
