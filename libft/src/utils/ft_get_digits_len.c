/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:41:21 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_get_digits_len(int n)
{
	int	len;
	int	nbr;

	if (n == 0)
		return (1);
	len = 0;
	nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}
