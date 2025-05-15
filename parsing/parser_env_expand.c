/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:32:18 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 14:57:20 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*expand_arg_continue(char *str, char c)
{
	char	*expanded;
	char	save[2];
	char	*temp;

	save[0] = c;
	save[1] = '\0';
	temp = str;
	expanded = ft_strjoin(str, save);
	if (!expanded)
		return (NULL);
	free(temp);
	return (expanded);
}

char	*ft_getpid(char *expanded)
{
	char	*environment;
	char	*temp;

	environment = ft_itoa(getpid());
	if (environment)
	{
		temp = expanded;
		expanded = ft_strjoin(expanded, environment);
		free(temp);
		free(environment);
	}
	return (expanded);
}

char	*process_env_variable(char *expanded, char *str, int *index)
{
	char	*environment;
	char	*temp;
	char	*variable;
	int		start;

	if (str[*index] == 36)
		return (ft_getpid(expanded));
	start = *index;
	while (str[*index] && !is_space(str[*index]))
		(*index)++;
	variable = ft_substr(str, start, *index - start);
	if (!variable)
	{
		free(expanded);
		return (NULL);
	}
	environment = getenv(variable);
	free(variable);
	if (environment)
	{
		temp = expanded;
		expanded = ft_strjoin(expanded, environment);
		free(temp);
	}
	return (expanded);
}

char	*expand_argv_while(char *str, char *expanded, int *index)
{
	if (str[*index] == 36 && str[*index + 1] && !is_space(str[*index + 1]))
	{
		(*index)++;
		expanded = process_env_variable(expanded, str, index);
		if (!expanded)
			return (NULL);
	}
	else
	{
		expanded = expand_arg_continue(expanded, str[*index]);
		if (!expanded)
			return (NULL);
		(*index)++;
	}
	return (expanded);
}

char	*expand_argv(char *str, int *index)
{
	char	*expanded;

	if (!str)
		return (NULL);
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	(*index) = 0;
	while (str[*index])
	{
		expanded = expand_argv_while(str, expanded, index);
		if (!expanded)
			return (NULL);
	}
	(*index) += ft_strlen(expanded);
	while (*index >= 0 && expanded[*index] == 32)
		expanded[(*index)--] = '\0';
	return (expanded);
}
