
#include "../minishell.h"
#include "../parser.h"

char	**command_chopper(char *line)
{
	char	**seg;

	if (words_counter(line) == 1)
		seg[0] = line;
	return (seg);
}

shell_line_t	*command_node(char *line)
{
	shell_line_t	*command;

	command = (shell_line_t *)malloc(sizeof(shell_line_t));
	if (!command)
	{
		free(command);
		return (NULL);
	}
	command->line = ft_strdup(line);
	command->cmd = command_chopper(line);
	command->next = NULL;
}

shell_line_t	*command_struct(char *line)
{
	shell_line_t	*commands;
	shell_line_t	*temp;
	char			**lines;
	int				index;

	lines = ft_split(line, '|');
	if (!lines)
		return ;
	commands = NULL;
	while (lines[index++])
	{
		if (!commands)
		{
			commands = command_node(lines[index]);
			temp = commands;
		}
		else
		{
			temp->next = command_code(lines[index]);
			temp = temp->next;
		}
	}
	free_double_char(lines);
	return (commands);
}
