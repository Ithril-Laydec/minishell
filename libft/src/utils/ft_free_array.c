/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:35 by itjimene          #+#    #+#             */
/*   Updated: 2025/02/26 17:06:25 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	if (array)
		free(array);
}
