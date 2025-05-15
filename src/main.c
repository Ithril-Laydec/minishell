# include "minishell.h"


int	main(int argc, char **argv, char **envs)
{
	data_t	*d;

	d = NULL;
	if (argc > 1 && argv)
		custom_exit(NULL, "Error: Too many arguments");
	init_data(&d, envs);
	init_signals();
	print_ascii_art("shellder.txt");
	loop(d);
	free_data(d);
	return (0);
}
void	loop(data_t *d)
{
	char	*prompt;

	while (42)
	{
		prompt = prompter(d);
		d->line = readline(prompt);
		free(prompt);
		if (d->line == NULL)
			custom_exit(d, "exit\n");
		add_history(d->line);
		d->sh_ln = command_struct(d);
		if (d->sh_ln == NULL)
		{
			ft_printf("\n");
			free(d->line);
			d->line = NULL;
			continue;
		}
		executer(d);
		ft_printf("\n");
		free(d->line);
		d->line = NULL;
		free(d->sh_ln->line);
		d->sh_ln->line = NULL;
		free(d->sh_ln->cmd);
		d->sh_ln->cmd = NULL;
	}
}