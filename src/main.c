# include "minishell.h"

// int	g_exit_status;

int	main(int argc, char **argv, char **envs)
{
	data_t	*d;

	d = NULL;
	if (argc > 1 && argv)
		error(NULL, "Error: Too many arguments");
	init_data(&d, envs);
	loop(d);
	free_data(d);
	return (0);
}
void	loop(data_t *d)
{
	while (42)
	{
		printf("%s",prompter(d));
		d->line = readline("");
		// d->line = aux;
		if (d->line == NULL)
			break;
		add_history(d->line);
		// d->sh_ln = parser(d->line);
		// if (d->sh_ln == NULL)
		// {
		// 	printf("Error parsing line\n");
		// 	free(d->line);
		// 	continue;
		// }
		// executer(d);
		// free(d->sh_ln);
		printf("%s\n", d->line);
	}
}
