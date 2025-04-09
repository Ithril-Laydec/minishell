/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:06:51 by itjimene          #+#    #+#             */
/*   Updated: 2025/03/01 19:47:26 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static double	parse_integral(const char **str)
{
	double	integral;

	integral = 0.0;
	while (**str && ft_isdigit(**str))
	{
		integral = integral * 10 + ((**str) - '0');
		(*str)++;
	}
	return (integral);
}

static double	parse_fraction(const char **str)
{
	double	frac;
	double	divisor;

	frac = 0.0;
	divisor = 10.0;
	while (**str && ft_isdigit(**str))
	{
		frac += ((**str) - '0') / divisor;
		divisor *= 10;
		(*str)++;
	}
	return (frac);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	if (!str)
		return (0.0);
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0.0);
	result = parse_integral(&str);
	if (*str == '.')
	{
		str++;
		fraction = parse_fraction(&str);
		result += fraction;
	}
	return (sign * result);
}
