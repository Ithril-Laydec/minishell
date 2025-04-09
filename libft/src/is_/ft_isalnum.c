/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:15:02 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/27 10:08:36 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_isalnum(int arg)
{
	if (ft_isalpha(arg) || ft_isdigit(arg))
		return (1);
	return (0);
}
