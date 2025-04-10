#include "../minishell.h"

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
	free(d);
}

void	error(data_t *d, char *msg)
{
	free_data(d);
	if (msg != NULL)
		perror(msg);
	exit(EXIT_FAILURE);
}