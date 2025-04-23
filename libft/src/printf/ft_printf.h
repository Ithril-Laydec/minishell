/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/04/22 12:44:38 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"

typedef struct s_types
{
	unsigned long long	ull_arg;
	int					int_arg;
	char				char_arg;
	char				*str_arg;
	unsigned int		uint_arg;
}				t_types;

typedef struct s_flags
{
	char	type;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		precision;
	int		width;
	int		printed_minus;
	int		null_str;
}				t_flags;

typedef struct s_vars
{
	va_list		args;
	char const	*format;
	int			f_index;
	int			printed_bytes;
	t_flags		*flags;
	t_types		*types;
}				t_vars;

int		ft_printf(char const *format, ...);
int		init_vars(t_vars **vars, char const *format, va_list args);
void	process_argument(t_vars *vars);
void	analyze_minus(t_vars *vars);
void	analyze_precision(t_vars *vars);
void	analyze_plus(t_vars *vars);
void	analyze_space(t_vars *vars);
void	analyze_hash(t_vars *vars);
void	analyze_width(t_vars *vars);
void	analyze_zero(t_vars *vars);
void	print_minus(t_vars *vars);
void	process_pre_flags(t_vars *vars);
void	process_post_flags(t_vars *vars);
void	choose_template(t_vars *vars);
void	zero_flag(t_vars *vars);
void	minus_flag(t_vars *vars);
void	plus_flag(t_vars *vars);
void	space_flag(t_vars *vars);
void	hash_flag(t_vars *vars);
void	precision_flag(t_vars *vars);
void	width_flag(t_vars *vars);
int		get_printable_len(t_vars *vars);
int		count_digits_in_integer(unsigned long long n);
int		count_digits_in_unsigned(unsigned int n);
int		count_digits_in_hex(unsigned long long n);
int		init_flags(t_vars *vars);
int		init_types(t_vars *vars);
void	clear_flags(t_vars *vars);
void	clear_types(t_vars *vars);
void	process_c(t_vars *vars);
void	process_s(t_vars *vars);
void	process_p(t_vars *vars);
void	process_d_i(t_vars *vars);
void	process_u(t_vars *vars);
void	process_x(t_vars *vars);
void	process_x_upper(t_vars *vars);

#endif
