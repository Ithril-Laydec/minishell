
#include "../minishell.h"

shell_line_t	*command_node(char *line)
{
	shell_line_t	*command;

	command = (shell_line_t *)malloc(sizeof(shell_line_t));
	if (!command)
	{
		free(command);
		return (NULL);
	}
	command->line = ft_strndup(line, no_space_finder(line));
	command->cmd = ft_split(line, ' ');
	command->next = NULL;
	return (command);
}

shell_line_t	*command_struct(data_t *d)
{
	shell_line_t	*commands;
	shell_line_t	*temp;
	char			**lines;
	int				index;

	index = 0;
	d->line = ft_strndup(d->line, no_space_finder(d->line));
	lines = ft_split(d->line, '|');
	commands = NULL;
	while (lines[index])
	{
		if (!commands)
		{
			commands = command_node(lines[index]);
			temp = commands;
		}
		else
		{
			temp->next = command_node(lines[index]);
			temp = temp->next;
		}
		index++;
	}
	free_double_char(lines);
	return (commands);
}
