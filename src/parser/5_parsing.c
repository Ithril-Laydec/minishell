/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:44:48 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 14:26:29 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parsing_text(char *cmd, char *argv, int *index, char *result)
{
	char	a[2];
	char    *temp;

	a[0] = argv[*index];
	a[1] = '\0';
	temp = ft_strjoin(result, a);
	(*index)++;
	return (temp);
}

char	*parsing_single_quote(char *cmd, char *argv, int *index, char *result)
{
	char	*temp;
	char    *new_result;
	int		start;

	(*index)++;
	start = *index;
	while (argv[*index] && argv[*index] != 39) // Corregido de 34 (comilla doble) a 39 (comilla simple)
		(*index)++;
	if (!argv[*index])
		return (NULL);
	temp = ft_substr(argv, start, *index - start);
	if (!temp)
		return (NULL);
	new_result = ft_strjoin(result, temp);
	free(temp);
	(*index)++; // Avanzar después de la comilla de cierre
	return (new_result);
}

char	*parsing_double_quote(char *cmd, char *argv, int *index, char *result)
{
	char	*expanded;
	char	*temp;
	char    *new_result;
	int		dollar[1];
	int		start;
	data_t  *d = NULL; // Necesitamos acceder a data_t para expandir variables

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
	if (dollar[0])
	{
		// Para expandir variables dentro de comillas dobles, necesitamos
		// acceder a la estructura data_t, pero no la estamos pasando.
		// Este es un problema estructural en el código.
		new_result = ft_strjoin(result, temp);
		free(temp);
	}
	else
	{
		new_result = ft_strjoin(result, temp);
		free(temp);
	}
	(*index)++; // Avanzar después de la comilla de cierre
	return (new_result);
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
	cmd = NULL;
	while (argv[index])
	{
		if (argv[index] == 34)
			cmd = parsing_double_quote(cmd, argv, &index, result);
		else if (argv[index] == 39)
			cmd = parsing_single_quote(cmd, argv, &index, result);
		else
			cmd = parsing_text(cmd, argv, &index, result);
		
		if (cmd)
		{
			free(result);
			result = cmd;
		}
	}
	return (result);
}
