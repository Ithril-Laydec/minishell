#include "../minishell.h"


void	executer(data_t *d)
{
	pid_t	pid;
	int		status;
	printf("executer\n");

	if (!d->sh_ln->cmd)
	{
		printf("No hay comandos\n");
		return;
	}
	if (!d->sh_ln || !d->sh_ln->cmd || !d->sh_ln->cmd[0])
		return;
	// Built-ins
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		printf("hijo\n");
		if (execve(d->sh_ln->cmd[0], d->sh_ln->cmd, d->str_env) == -1)
		{
			perror(d->sh_ln->cmd[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("padre\n");
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
}
