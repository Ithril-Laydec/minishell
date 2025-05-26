/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/05/26 10:06:15 by aternero         ###   ########.fr       */
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

/* shell_line_t	*command_node(char *line);
shell_line_t	*command_struct(char *line); */
char			*parsing(char *argv);
char			**to_split(char *temp, char *str);
char			**parsing_split(char const *s, char c);
char			*single_quotes_copy(char *str, int *index);
char			*expand_argv(char *str, int *index);
char			*expand_argv_while(char *str, char *expanded, int *index);
char			*process_env_variable(char *expanded, char *str, int *index);
void			ft_getpid(int *index);
char			*expand_arg_continue(char *str, char c);
int				is_there_quotes(char *str);
int				is_there_dollars(char *str);
int				words_counter(char *str);
int				is_space(char c);
char			*remove_spaces(char *str);
int				is_operator(char c);
char			**to_split(char *temp, char *str);
char			**no_quotes_expand(char *str, int dollar);
char			*parsing_text(char *cmd, char *argv, int *index, char *result);
char			*parsing_single_quote(char *cmd, char *argv, int *index, char *result);
char			*parsing_double_quote(char *cmd, char *argv, int *index, char *result);
int				flag_calculator(char *line, int index, int quote);

	// LIBFT
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);

#endif