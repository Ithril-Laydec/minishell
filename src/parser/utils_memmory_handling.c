/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memmory_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:08:46 by aternero          #+#    #+#             */
/*   Updated: 2025/05/28 13:15:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	array_free(char **array)
{
	int	index;

	if (!array)
		return ;
	index = -1;
	while (array[++index])
	{
		if (array[index])
			free(array[index]);
	}
	free(array);
}

void	free_double_char(char **str)
{
	int	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		free(str[index]);
		str[index] = NULL;
	}
	free(str);
	str = NULL;
}
