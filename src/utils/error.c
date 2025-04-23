#include "../minishell.h"

void	free_envs(envs_t *envs)
{
	envs_t	*tmp;

	while (envs)
	{
		tmp = envs;
		envs = envs->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

void	free_data(data_t *d)
{
	if (!d)
		return ;
	if (d->sh_ln)
	{
		if (d->sh_ln->line)
			free(d->sh_ln->line);
		if (d->sh_ln->cmd)
			free(d->sh_ln->cmd);
		if (d->sh_ln->redir)
			free(d->sh_ln->redir);
		free(d->sh_ln);
	}
	if (d->line)
		free(d->line);
	if (d->user)
		free(d->user);
	if (d->pwd)	
		free(d->pwd);
	if (d->envs)	
		free_envs(d->envs);
	if (d->str_env)
		ft_free_array(d->str_env);
	free(d);
}

void	error(data_t *d, char *msg)
{
	free_data(d);
	if (msg != NULL)
		perror(msg);
	exit(EXIT_FAILURE);
}