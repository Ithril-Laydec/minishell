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
		tmp = NULL;
	}
}
void	free_redirects(refirect_t *redir)
{
	refirect_t	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		if (tmp->type)
			free(tmp->type);
		if (tmp->file)
			free(tmp->file);
		free(tmp);
		tmp = NULL;
	}
}

void	free_shell_line(shell_line_t *sh_ln)
{
	shell_line_t	*current;
	shell_line_t	*next;

	current = sh_ln;
	while (current)
	{
		next = current->next;
		if (current->line)
			free(current->line);
		if (current->cmd)
			free(current->cmd);
		if (current->redir)
			free_redirects(current->redir);
		free(current);
		current = next;
	}
}

void	free_data(data_t *d)
{
	if (!d)
		return ;
	if (d->sh_ln)
		free_shell_line(d->sh_ln);
	if (d->line)
		free(d->line);
	if (d->envs)	
		free_envs(d->envs);
	if (d->str_env)
		ft_free_array(d->str_env);
	free(d);
}

void	custom_exit(data_t *d, char *msg)
{
	free_data(d);
	if (msg != NULL)
		perror(msg);
	exit(EXIT_FAILURE);
}
