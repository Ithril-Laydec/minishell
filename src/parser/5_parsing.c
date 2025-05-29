/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:44:48 by aternero          #+#    #+#             */
/*   Updated: 2025/05/29 20:14:21 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parsing_text(char *argv, int *index, char *result)
{
	char	a[2];
	char    *temp;
	char    *old_result;

	a[0] = argv[*index];
	a[1] = '\0';
	old_result = result;
	temp = ft_strjoin(result, a);
	free(old_result);
	(*index)++;
	return (temp);
}

char	*parsing_single_quote(char *argv, int *index, char *result)
{
	char	*temp;
	char    *new_result;
	char    *old_result;
	int		start;

	(*index)++;
	start = *index;
	while (argv[*index] && argv[*index] != 39)
		(*index)++;
	if (!argv[*index])
		return (NULL);
	temp = ft_substr(argv, start, *index - start);
	if (!temp)
		return (NULL);
	old_result = result;
	new_result = ft_strjoin(result, temp);
	free(temp);
	free(old_result);
	(*index)++;
	return (new_result);
}

char	*parsing_double_quote(char *argv, int *index, char *result)
{
	char	*temp;
	char	*new_result;
	char	*old_result;
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
	old_result = result;
	new_result = ft_strjoin(result, temp);
	free(temp);
	free(old_result);
	(*index)++;
	return (new_result);
}

char	*parsing_continue(char	*argv)
{
	char	*result;
	int		index;

	if (!argv)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	index = 0;
	while (argv[index])
	{
		if (argv[index] == 34)
			result = parsing_double_quote(argv, &index, result);
		else if (argv[index] == 39)
			result = parsing_single_quote(argv, &index, result);
		else
			result = parsing_text(argv, &index, result);
		
		if (!result)
			return (NULL);
	}
	return (result);
}
