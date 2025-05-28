/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_no_quotes_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:13:24 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 14:27:57 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*no_quotes_expand(char *str, data_t *d)
{
	char	*expanded;
	char	*temp;
	int		index;

	if (!str)
		return (NULL);
	if (is_there_dollars(str) == 0)
		return (str);
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] == '$' && str[index + 1]
			&& is_space(str[index + 1]) == 0)
		{
			index++;
			expanded = process_env_variable(d, expanded, str, &index);
			if (!expanded)
				return (NULL);
		}
		else
		{
			expanded = continue_expand(expanded, str[index]);
			if (!expanded)
				return (NULL);
			index++;
		}
	}
	return (expanded);
}
