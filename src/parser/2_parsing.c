/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:11:46 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 14:26:29 by itjimene         ###   ########.fr       */
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
		return (cmd);
	}
	else
	{
		cmd = parsing_continue(str);
		if (!cmd)
		{
			free(str);
			return (NULL);
		}
		free(str);
		return (cmd);
	}
}
