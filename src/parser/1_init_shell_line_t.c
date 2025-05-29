/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_shell_line_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:07:33 by aternero          #+#    #+#             */
/*   Updated: 2025/05/29 23:32:39 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

shell_line_t	*command_node(char *line, data_t *d)
{
	shell_line_t	*command;
	char			**temp;
	int				yndex;

	command = (shell_line_t *)ft_calloc(1, sizeof(shell_line_t));
	if (!command)
		return (NULL);
	command->line = ft_strtrim(line, " ");
	if (!command->line)
	{
		free(command);
		return (NULL);
	}
	temp = parsing_split(line, ' ');
	if (!temp)
	{
		free(command->line);
		free(command);
		return (NULL);
	}
	command->cmd = (char **)ft_calloc(sizeof(char *), (parsing_count_words(line, ' ') + 1));
	if (!command->cmd)
	{
		free(command->line);
		array_free(temp);
		free(command);
		return (NULL);
	}
	yndex = -1;
	while (temp[++yndex])
	{
		command->cmd[yndex] = parsing(temp[yndex], d);
		if (!command->cmd[yndex])
		{
			int i = 0;
			while (i < yndex)
				free(command->cmd[i++]);
			free(command->cmd);
			free(command->line);
			array_free(temp);
			free(command);
			return (NULL);
		}
	}
	command->cmd[yndex] = NULL;
	array_free(temp);
	command->next = NULL;
	command->redir = NULL;
	return (command);
}

shell_line_t	*command_struct(char *line, data_t *d)
{
	shell_line_t	*commands;
	shell_line_t	*temp;
	char			**lines;
	int				index;

	index = 0;
	lines = parsing_split(line, '|');
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
	array_free(lines);
	return (commands);
}
