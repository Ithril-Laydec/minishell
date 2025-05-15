/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_level_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:30 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 14:51:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**no_quotes_expand(char *str, int dollar)
{
	char	*temp;

	if (!str)
		return (NULL);
	if (dollar == 0)
		return (ft_split(str, 32));
	temp = expand_argv(str);
	if (!temp)
		return (NULL);
	return (to_split(temp, str));
}
