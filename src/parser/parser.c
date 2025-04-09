
#include "../minishell.h"

void	free_double_char(char **str)
{
	if (!str || !*str)
		return ;
	while (*str)
	{
		free(*str);
		str = NULL;
	}
	free(str);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	words_counter(char *line)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (is_space(line[index]) == 1)
		index++;
	if (line[index] && is_space(line[index]) == 0)
		count++;
	while (line[index++])
	{
		if (is_space(line[index]) == 1
			&& (line[index + 1] && is_space(line[index + 1]) == 0))
			count++;
	}
	return (count);
}

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
		return ;
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
