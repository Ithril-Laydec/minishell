/* 
#ifndef PARSER_H
# define PARSER_H

SUBJECT
	Un programa que recibe una línea entera y la devuelve conforme a las
	interpretaciones en bash y siguiendo el parseo preestablecido en el
	subject de minishell.


// ** INCLUDES .H ** ...........................................................

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
//# include "../minishell.h"

// ** STRUCTURES ** ............................................................

typedef struct s_shell_line
{
	char				*line;
	char				**cmd;
	struct s_shell_line	*next;
}						shell_line_t;

DISCLAMER
	- LINE == La línea entera
	- CMD == Los comandos troceados
	- REDIR == las redirecciones


typedef struct s_data
{
	char				*line;
	struct s_shell_line	*sh_ln;
	char				**str_env;
	struct s_envs		*envs; // Lista enlazada para el export
	char				*user;
	// char				*host;
	char				*pwd;
	int					exit_status; // Sustituir por variable global
	// char				*prompt;
}						data_t;

// ** FUNCTIONS ** .............................................................

	//	**	INIT SHELL_LINE_T
shell_line_t	*command_node(char *line, data_t *d);
shell_line_t	*command_struct(char *line, data_t *d);

	//	**	PARSING
char			*parsing(char *str, data_t *d);

	//	**	NO QUOTES EXPAND
char			*no_quotes_expand(char *str, data_t *d);

	//	**	EXPAND VAR
char			*process_env_variable(data_t *d, char *expanded, char *str, int *index);
char			*continue_expand(char *expanded, char c);

	//	**	PARSING
char			*parsing_continue(char	*argv);
char			*parsing_double_quote(char *cmd, char *argv, int *index, char *result);
char			*parsing_single_quote(char *cmd, char *argv, int *index, char *result);
char			*parsing_text(char *cmd, char *argv, int *index, char *result);

	//	**	FINDER
int				is_there_quotes(char *str);
int				is_there_dollars(char *str);
int				is_space(char c);
int				no_space_finder(char *str);
int				flag_calculator(char *line, int index, int quote);

	//	**	PARSING SPLIT
char			**parsing_split(char const *s, char c);

	//	**	MEMMPORY HANDLING
void			array_free(char **array);
void			free_double_char(char **str);

	//	**	STRNDUP
char			*ft_strndup(const char *str, int init);

#endif
 */