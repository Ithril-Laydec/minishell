

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct s_redirect
{
	char				*type;	// > < << >>
	char				*file;	// archivo .txt
	struct s_redirect	*next;
}						refirect_t;


typedef struct s_shell_line
{
	char				*line;	// La línea entea
	char				**cmd;	// Los comandos troceados
	struct s_redirect	*redir;	// Las redcirecciones
	struct s_shell_line	*next;
}						shell_line_t;

typedef struct s_envs
{
	char				*name;	// Nombre de la variable
	char				*value;	// Valor de la variable
	// int					index;
	struct s_envs		*next;
}						envs_t;

typedef struct s_data
{
	char				*line;
	struct s_shell_line	*sh_ln;
	char				**str_env;
	struct s_envs		*envs; // Lista enlazada para el export
	char				*user;
	// char				*host;
	char				*pwd;
	// char				*prompt;
}						data_t;

/* Utils */
void			init_data(data_t **d, char **env);
void			free_data(data_t *d);
char			*ft_getenv(char *name, data_t *d);
void			ft_setenv(char *name, char *value, data_t *d);
char			*prompter(data_t *d);

/* Secure Alloc, forces etix if malloc fails */
void			*salloc(size_t size, data_t *d);

/* Print an error and exit */
void			error(data_t *d, char *msg);
void			print_ascii_art(const char *filename);

/* Parser */
shell_line_t	*command_struct(char *line);
shell_line_t	*command_node(char *line);
void			free_double_char(char **str);
int				no_space_finder(char *str);
char			*ft_strndup(const char *str, size_t init);

/* Buildt-ins */
void			echo(char **cmd, data_t *d);
void			cd(char **cmd, data_t *d);
void			pwd(data_t *d);
void			export(char **cmd, data_t *d);
void			unset(char **cmd, data_t *d);
void			env(data_t *d);
void			exit_shell(data_t *d);

/* Envs */
void			ft_setenv(char *name, char *value, data_t *d);
void			ft_unsetenv(char *name, data_t *d);



/* Executer */
void			loop(data_t *d);
void			executer(data_t *d);



#endif