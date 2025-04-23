/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:04:10 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putnbr_base_fd(unsigned long long n, char *base, int fd)
{
	unsigned int	len;
	char			c;
	char			*string;
	int				printed;

	len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", fd);
		n = -n;
	}
	if (n >= len)
	{
		ft_putnbr_base_fd(n / len, base, fd);
		ft_putnbr_base_fd(n % len, base, fd);
	}
	else
	{
		c = base[n];
		write(1, &c, fd);
	}
	string = ft_lotoa_base(n, base);
	printed = ft_strlen(string);
	free(string);
	return (printed);
}
