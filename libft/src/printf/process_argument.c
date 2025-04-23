/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:52:06 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:51:41 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_token(char c)
{
	if (c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == '%')
		return (1);
	return (0);
}

static char	get_arg_type(char const *format)
{
	while (*format && !is_token(*format))
		format++;
	return (*format);
}

void	process_argument(t_vars *vars)
{
	clear_flags(vars);
	clear_types(vars);
	vars->flags->type = get_arg_type(vars->format);
	while (*vars->format && !is_token(*vars->format))
	{
		analyze_minus(vars);
		analyze_precision(vars);
		analyze_plus(vars);
		analyze_space(vars);
		analyze_hash(vars);
		analyze_zero(vars);
		analyze_width(vars);
	}
	choose_template(vars);
}
