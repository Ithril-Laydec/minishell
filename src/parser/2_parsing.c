/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:11:46 by aternero          #+#    #+#             */
/*   Updated: 2025/05/27 14:19:55 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parsing(char *str, data_t *d)
{
	char	*cmd;

	if (is_there_quotes(str) == 0)
	{
		cmd = no_quotes_expand(str, d);
		if (!cmd)
		{
			free(str);
			return (NULL);
		}
	}
	cmd = parsing_continue(str);
	if (!cmd)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (cmd);
}
