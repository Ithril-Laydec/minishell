/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:35:09 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 12:38:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static int	ft_get_digits_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr > 10)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	get_next_digit(int n, int i)
{
	int	d;
	int	len;

	if (n == -2147483648 && i == 9)
		return (8);
	len = ft_get_digits_len(n);
	if (n < 0)
		len--;
	d = 0;
	while (d < len - i - 1)
	{
		n /= 10;
		d++;
	}
	if (n < 0)
		n = -n;
	return (n % 10);
}

char	*ft_itoa(int n)
{
	char	*str_nb;
	int		i;
	int		len;

	len = ft_get_digits_len(n);
	str_nb = malloc(sizeof(char) * (len + 1));
	if (!str_nb)
		return (NULL);
	if (n < 0)
	{
		str_nb[0] = '-';
		str_nb++;
		len--;
	}
	i = 0;
	while (i < len)
	{
		str_nb[i] = '0' + get_next_digit(n, i);
		i++;
	}
	str_nb[i] = '\0';
	if (n < 0)
		str_nb--;
	return (str_nb);
}
