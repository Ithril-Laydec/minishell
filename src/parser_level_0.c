/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_level_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:30 by aternero          #+#    #+#             */
/*   Updated: 2025/05/26 11:20:23 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**no_quotes_expand(char *str, int dollar)
{
	char	*temp;
	int		index;

	if (!str)
		return (NULL);
	if (dollar == 0)
		return (parsing_split(str, 32));
	index = 0;
	while (str[index])
	{
		if (str[index] == 36)
			temp = expand_argv(str, &index);
		index++;
	}
	if (!temp)
		return (NULL);
	return (to_split(temp, str));
}
