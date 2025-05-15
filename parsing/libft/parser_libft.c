/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:02 by aternero          #+#    #+#             */
/*   Updated: 2025/05/14 19:53:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		index;
	int		index_b;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		join[index] = s1[index];
		index++;
	}
	index_b = 0;
	while (s2[index_b])
	{
		join[index] = s2[index_b];
		index++;
		index_b++;
	}
	join[index] = '\0';
	return (join);
}
