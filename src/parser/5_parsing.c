/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:44:48 by aternero          #+#    #+#             */
/*   Updated: 2025/05/27 14:21:18 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parsing_text(char *cmd, char *argv, int *index, char *result)
{
	char	a[2];

	a[0] = argv[*index];
	a[1] = '\0';
	cmd = ft_strjoin(result, a);
	(*index)++;
	return (cmd);
}

char	*parsing_single_quote(char *cmd, char *argv, int *index, char *result)
{
	char	*temp;
	int		start;

	(*index)++;
	start = *index;
	while (argv[*index] && argv[*index] != 34)
		(*index)++;
	if (!argv[*index])
		return (NULL);
	temp = ft_substr(argv, start, *index - start);
	if (!temp)
		return (NULL);
	cmd = ft_strjoin(result, temp);
	free(temp);
	return (cmd);
}

char	*parsing_double_quote(char *cmd, char *argv, int *index, char *result)
{
	char	*expanded;
	char	*temp;
	int		dollar[1];
	int		start;

	dollar[0] = 0;
	(*index)++;
	start = *index;
	while (argv[*index] && argv[*index] != 34)
		(*index)++;
	if (!argv[*index])
		return (NULL);
	temp = ft_substr(argv, start, *index - start);
	if (!temp)
		return (NULL);
	dollar[0] = is_there_dollars(temp);
	expanded = parsing_continue(temp);
	free(temp);
	if (!expanded)
		return (NULL);
	cmd = ft_strjoin(result, expanded);
	free(expanded);
	return (cmd);
}

char	*parsing_continue(char	*argv)
{
	char	*cmd;
	char	*result;
	int		index;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	index = 0;
	while (argv[index])
	{
		if (argv[index] == 34)
			cmd = parsing_double_quote(cmd, argv, &index, result);
		if (argv[index] == 39)
			cmd = parsing_single_quote(cmd, argv, &index, result);
		else
			cmd = parsing_text(cmd, argv, &index, result);
	}
	if (!cmd)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
