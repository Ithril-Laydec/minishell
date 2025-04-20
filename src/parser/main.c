
#include "../minishell.h"
#include "../parser.h"

int	main(int argc, char **argv)
{
	shell_line_t	*commands;

	(void)argc;
	commands = command_struct(argv[1]);

	(void)commands;
	/*
	while (commands)
	{
		printf("%s\n", commands->line);
		commands = commands->next;
	}
	*/
}
