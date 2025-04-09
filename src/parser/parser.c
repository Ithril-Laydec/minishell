
#include "../minishell.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))	
		return (1);
	return (0);
}

shell_line_t	*command_node(char *line)
{
	shell_line_t	*command;

	command = (shell_line_t *)malloc(sizeof(shell_line_t));
	if (!command)
	{
		free(command);
		return ;
	}
	command->line = ft_strdup(line);
	command->cmd = cmd_chopper(line);
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
