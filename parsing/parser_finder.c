/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:10:33 by aternero          #+#    #+#             */
/*   Updated: 2025/05/14 19:10:43 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_there_dollars(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == 36)
			return (1);
	}
	return (0);
}

int	is_there_quotes(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == 34)
			return (2);
		if (str[index] == 39)
			return (1);
	}
	return (0);
}
