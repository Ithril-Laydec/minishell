/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_shell_line_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:07:33 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 13:58:45 by aternero         ###   ########.fr       */
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
	{
		free(command);
		return (NULL);
	}
	command->line = ft_strtrim(line, " ");
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
		free(command);
		array_free(temp);
		free(command);
		return (NULL);
	}
	yndex = -1;
	while (temp[++yndex])
		command->cmd[yndex] = parsing(temp[yndex], d);
	command->cmd[yndex] = NULL;
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
//	commands->line = ft_strtrim(line, " ");
	lines = parsing_split(line, '|');
	//free(commands->line);
	commands = NULL;
	while (lines[index])
	{
		if (!commands)
		{
			//ft_prin
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
