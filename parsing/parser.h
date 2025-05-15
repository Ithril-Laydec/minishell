/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:07 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 14:55:20 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* SUBJECT
	Un programa que recibe una línea entera y la devuelve conforme a las
	interpretaciones en bash y siguiendo el parseo preestablecido en el
	subject de minishell.
*/

// ** INCLUDES .H ** ...........................................................

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

// ** STRUCTURES ** ............................................................

typedef struct s_shell_line
{
	char				*line;
	char				**cmd;
	struct s_shell_line	*next;
}	t_shell_line;

/* DISCLAMER
	- LINE == La línea entera
	- CMD == Los comandos troceados
	- REDIR == las redirecciones
*/

// ** FUNCTIONS ** .............................................................

	//	MAIN
char	**parsing(char *argv);
char	**to_split(char *temp, char *str);
char	*single_quotes_copy(char *str, int *index);

	// ENV EXPAND
char	*expand_argv(char *str, int *index);
char	*expand_argv_while(char *str, char *expanded, int *index);
char	*process_env_variable(char *expanded, char *str, int *index);
char	*ft_getpid(char *expanded);
char	*expand_arg_continue(char *str, char c);

	// FINDER
int		is_there_quotes(char *str);
int		is_there_dollars(char *str);

	// LIBFT
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
		// SPLIT
char	**ft_split(char const *s, char c);
		// SUBSTR
char	*ft_substr(char const *s, unsigned int start, size_t len);
		// STRDUP
char	*ft_strdup(const char *s);
		// ITOA
char	*ft_itoa(int n);
		// STRTRIM
char	*ft_strtrim(char const *s1, char const *set);

	// UTILS
int		words_counter(char *str);
int		is_space(char c);
char	*remove_spaces(char *str);
int		is_operator(char c);
char	**to_split(char *temp, char *str);

	// LEVEL 0
char	**no_quotes_expand(char *str, int dollar);

#endif