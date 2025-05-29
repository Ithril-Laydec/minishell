/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:11:46 by aternero          #+#    #+#             */
/*   Updated: 2025/05/29 22:04:00 by itjimene         ###   ########.fr       */
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
			return (NULL);
		return (cmd);
	}
	else
	{
		cmd = parsing_continue(str);
		if (!cmd)
			return (NULL);
		return (cmd);
	}
}
