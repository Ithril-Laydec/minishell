
#include "../minishell.h"


char	*find_the_next(char *str, int start, char quote)
{
	char	*temp;
	int		index;

	index = 0;
	while (str[start])
	{
		if (str[start] == quote)
			return (temp);
		temp[index] = str[start];
		index++;
		start++;
	}
	return (temp);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	flag_calculator(char *line, int index, int quote)
{
	if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 34 && quote == 0)
		return (1);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 34 && quote == 1)
		return (0);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 39 && quote == 0)
		return (2);
	else if ((!line[index - 1] || (line[index - 1] && line[index - 1] != 92))
		&& line[index] == 39 && quote == 2)
		return (0);
	return (quote);
}

char	*parsing_continue_0(char *str, data_t *d)
{
	char	*main;
	char	*temp_e;
	char	*temp;
	int		index;
	int		index_x;
	int		quote;

	index = 0;
	index_x = 0;
	while (str[index])
	{
		if (str[index] == 34 && quote != 2)
		{
			if (quote == 0)
				quote == 1;
			else
				quote == 0;
			index++;
		}
		if (str[index] == 36 && quote == 0)
		{
			temp = find_the_next(str, index + 1, 32);
			temp_e = ft_getenv(temp, d);
			ft_strjoin(main, temp);
			index += ft_strlen(temp) + 1;
		}
		if (str[index] == 39 && quote != 1)
		{
			if (quote == 0)
				quote == 2;
			else
				quote == 0;
			index++;
		}
		else
		{
			main[index_x] = str[index];
			index++;
			index_x++;
		}
	}
	main[index_x] = '\0';
	return (main);
}

char	**parsing_development(char *line, data_t *d)
{
	char	**cmd;	// comandos troceados para la estructura
	char	**temp; // almacena temporalmente la variable expandida
	int		index; // para recorrer line y cmd
	cmd = (char *)malloc(sizeof(char *) * (words_counter(line) + 1));
	if (!cmd)
		return (NULL);
	temp = parsing_split(line, 32);
	index = 0;
	while (temp[++index])
	{
		cmd[index] = parsing_continue_0(temp[index], d);
		if (!cmd[index])
			return (NULL);
	}
	return (cmd);
}

shell_line_t	*command_node(char *line, data_t *d)
{
	shell_line_t	*command;
	int				yndex;

	command = (shell_line_t *)malloc(sizeof(shell_line_t));
	if (!command)
	{
		free(command);
		return (NULL);
	}
	command->line = ft_strndup(line, no_space_finder(line));
	if (quotations_counter(command->line, 34) % 2 != 0 || quotations_counter(command->line, 39) % 2 != 0)
		ft_printf("Not all inverted commas are closed.");
	command->cmd = ft_split(line, ' ');
	yndex = 1;
	while (command->cmd[yndex])
	{
		command->cmd[yndex] = command_expander(command->cmd[yndex], d);
		yndex++;
	}
	command->next = NULL;
	return (command);
}

shell_line_t	*command_struct(char *line, data_t *d)
{
	shell_line_t	*commands;
	shell_line_t	*temp;
	char			**lines;
	int				index;

	index = 0;
	line = ft_strndup(line, no_space_finder(line));
	lines = ft_split(line, '|');
	commands = NULL;
	while (lines[index])
	{
		if (!commands)
		{
			commands = command_node(lines[index], d);
			temp = commands;
		}
		else
		{
			temp->next = command_node(lines[index], d);
			temp = temp->next;
		}
		index++;
	}
	free_double_char(lines);
	return (commands);
}
