/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_no_quotes_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:13:24 by aternero          #+#    #+#             */
/*   Updated: 2025/05/27 14:21:06 by aternero         ###   ########.fr       */
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
	index = 0;
	while (str[index])
	{
		if (str[index] == 36 && str[index + 1]
			&& is_space(str[index + 1]) == 0)
		{
			index++;
			if (str[index] == 36)
			{
				printf("\nHere, you would receive PID\n");
				index++;
			}
			else
			{
				process_env_variable(d, expanded, str, &index);
				if (!expanded)
					return (NULL);
			}
		}
		else
		{
			continue_expand(expanded, str[index]);
			if (!expanded)
				return (NULL);
			index++;
		}
	}
	return (expanded);
}
