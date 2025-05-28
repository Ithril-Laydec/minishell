/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_expand_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:24:40 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 14:28:46 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*continue_expand(char *expanded, char c)
{
	char	*ret;
	char	*temp;
	char	saved[2];

	saved[0] = c;
	saved[1] = '\0';
	temp = expanded;
	ret = ft_strjoin(expanded, saved);
	if (!ret)
		return (NULL);
	free(temp);
	return (ret);
}

char	*process_env_variable(data_t *d, char *expanded, char *str, int *index)
{
	char	*env;
	char	*temp;
	char	*var;
	int		start;

	start = *index;
	while (str[*index] && (ft_isalnum(str[*index]) || str[*index] == '_'))
		(*index)++;
	var = ft_substr(str, start, *index - start);
	if (!var)
	{
		free(expanded);
		return (NULL);
	}
	env = ft_getenv(var, d);
	free(var);
	if (env)
	{
		temp = expanded;
		expanded = ft_strjoin(expanded, env);
		free(temp);
	}
	return (expanded);
}
