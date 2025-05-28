# include "minishell.h"


int	main(int argc, char **argv, char **envs)
{
	data_t	*d;

	d = NULL;
	if (argc > 1 && argv)
		custom_exit(NULL, "Error: Too many arguments", EXIT_FAILURE);
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
			custom_exit(d, "exit", EXIT_SUCCESS);
		add_history(d->line);
		d->sh_ln = command_struct(d->line, d);
		if (d->sh_ln == NULL)
		{
			ft_printf("\n");
			free(d->line);
			d->line = NULL;
			continue;
		}
		executer(d);
		if (g_signal == S_SIGINT || g_signal == S_SIGINT_CMD)
			g_signal = S_BASE;
		ft_printf("\n");
	}
}
