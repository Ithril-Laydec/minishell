/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:43 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 14:50:48 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**to_split(char *temp, char *str)
{
	char	**cmd;

	cmd = ft_split(temp, 32);
	if (!cmd)
	{
		free(str);
		return (NULL);
	}
	return (cmd);
}

int	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

char	*remove_spaces(char *str)
{
	char	*s2;
	int		index;
	int		aux;

	index = 0;
	aux = 0;
	while (str[index] && is_space(str[index]) == 1)
		index++;
	if (str[index] && is_space(str[index]) == 0)
		aux = index;
	index = ft_strlen(str);
	while (str[index] && is_space(str[index]) == 1)
		index--;
	if (is_space(aux) == 0 && is_space(index) == 0)
		s2 = ft_substr(str, aux, index - aux);
	else
	{
		if (is_space(aux) == 1)
			aux++;
		if (is_space(index) == 1)
			index--;
		s2 = ft_substr(str, aux, index - aux);
	}
	return (s2);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	words_counter(char *str)
{
	int	index;
	int	quote;
	int	words;

	if (!str)
		return (0);
	index = -1;
	quote = 0;
	words = 0;
	while (str[++index])
	{
		if (str[index] == 34 && quote == 0)
			quote = 2;
		else if (str[index] == 34 && quote == 2)
			quote = 0;
		else if (str[index] == 39 && quote == 0)
			quote = 1;
		else if (str[index] == 39 && quote == 1)
			quote = 0;
		else if (quote == 0 && is_space(str[index]) == 0
			&& (!str[index + 1] || is_space(str[index + 1]) == 1))
			words++;
	}
	return (words);
}
