# include "minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	data_t	*d;

	init_data(&d, env);
	while (42)
	{
		char *line = readline("minishell> ");
		if (line == NULL)
			break;
		add_history(line);
		shell_line_t *shell_line = parser(line);
		if (shell_line == NULL)
		{
			printf("Error parsing line\n");
			free(line);
			continue;
		}
		executer(shell_line);
		free(shell_line);
		free(line);
	}


}
