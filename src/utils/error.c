#include "../minishell.h"

void	free_data(data_t *d)
{
	if (d->shell_line != NULL)
	{
		free(d->shell_line->line);
		free(d->shell_line->cmd);
		free(d->shell_line->redir);
		free(d->shell_line);
	}
	if (d->envs != NULL)
	{
		for (int i = 0; d->envs[i] != NULL; i++)
			free(d->envs[i]);
		free(d->envs);
	}
	free(d);
}

void	error(data_t *d, char *msg)
{
	free_data(d);
	if (msg != NULL)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
}