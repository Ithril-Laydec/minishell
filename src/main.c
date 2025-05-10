# include "minishell.h"

int	main(int argc, char **argv, char **envs)
{
	data_t	*d;

	d = NULL;
	if (argc > 1 && argv)
		error(NULL, "Error: Too many arguments");
	init_data(&d, envs);
	print_ascii_art("shellder.txt");
	loop(d);
	free_data(d);
	return (0);
}
void	loop(data_t *d)
{
	while (42)
	{
		d->line = readline(prompter(d));
		if (d->line == NULL)
			break;
		// Comprobar si las comillas son pares o impares
		

		
		add_history(d->line);
		d->sh_ln = command_struct(d);
		if (d->sh_ln == NULL)
		{
			ft_printf("\n");
			free(d->line);
			continue;
		}
		executer(d);
		ft_printf("\n");
		free(d->line);
		free(d->sh_ln->line);
		free(d->sh_ln->cmd);
	}
}
