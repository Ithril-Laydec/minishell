/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:55 by aternero          #+#    #+#             */
/*   Updated: 2025/05/26 11:25:12 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**pre_parsing(char *argv)
{
	char	**cmd;
	char	**arg;
	int		index;

	cmd = NULL;
	if (is_there_quotes(argv) == 0)
	{
		index = 0;
		return (no_quotes_expand(argv, is_there_dollars(argv)));
	}
	arg = parsing_split(argv, 32);
	if (!arg)
		return (NULL);
	index = 0;
	while (arg[index])
		index++;
	cmd = malloc(sizeof(char *) * (index + 1));
	if (!cmd)
	{
		free(arg);
		return (NULL);
	}
	index = 0;
	while (arg[index])
	{
		cmd[index] = parsing(arg[index]);
		if (!cmd)
		{
			free(arg);
			return (NULL);
		}
		index++;
	}
	cmd[index] = NULL;
	free(arg);
	return (cmd);
}
/* 
shell_line_t	*command_node(char *line)
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
	command->cmd = parsing_split(line, ' ');
	yndex = 1;
	while (command->cmd[yndex])
	{
		command->cmd[yndex] = pre_parsing(command->cmd[yndex]);
		yndex++;
	}
	command->next = NULL;
	return (command);
}

shell_line_t	*command_struct(char *line)
{
	shell_line_t	*commands;
	shell_line_t	*temp;
	char			**lines;
	int				index;

	index = 0;
	line = ft_strndup(line, no_space_finder(line));
	lines = parsing_split(line, '|');
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
} */

int	main(int argc, char **argv)
{
	char	**cmd;
	int		yndex;

	if (argc != 2)
		return (0);
	cmd = pre_parsing(ft_strtrim(argv[1], " "));
	yndex = 0;
	while (cmd[yndex])
	{
		printf("%s\n", cmd[yndex]);
		yndex++;
	}
	return (0);
}
