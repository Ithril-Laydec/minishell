#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <signal.h>

extern int g_signal;

typedef enum e_signal
{
	S_BASE,        // señal Base
	S_HEREDOC,     // entra en el heredoc
	S_HEREDOC_END, // finalización del heredoc
	S_SIGINT,      // Ctrl + C
	S_SIGINT_CMD,  // Ctrl + C en medio de una comando
	S_CMD,         // se ejecuta un comando
	S_CANCEL_EXEC, // Ctrl + D en heredoc
	S_SIZE
}			t_signal;

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
	// char				*user;
	// char				*host;
	// char				*pwd;
	int					exit_status; // Sustituir por variable global
	// char				*prompt;
}						data_t;

/* Utils */
void			init_data(data_t **d, char **env);
char			**ft_str_array_dup(char **array);
void			free_data(data_t *d);
char			*ft_getenv(char *name, data_t *d);
void			ft_setenv(char *name, char *value, data_t *d);
char			*prompter(data_t *d);

/* Secure Alloc, forces etix if malloc fails */
void			*salloc(size_t size, data_t *d);

/* Print an error and exit */
void			custom_exit(data_t *d, char *msg, int exit_code);

/* Parser */
shell_line_t	*command_struct(data_t *d);
shell_line_t	*command_node(char *line);
void			free_double_char(char **str);
int				no_space_finder(char *str);
char			*ft_strndup(const char *str, size_t init);

/* Buildt-ins */
void			print_ascii_art(const char *filename);
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
// char			*find_command_path(const char *cmd, char **envp, data_t *d); // Se hará estática o se moverá
bool			is_builtin(const char *cmd);
bool			is_parent_builtin(const char *cmd);
int				execute_builtin(shell_line_t *cmd_node, data_t *d);
bool			handle_single_parent_builtin(data_t *d, int num_cmds);
int				execute_pipeline(data_t *d, int num_cmds, pid_t *pids);
void			setup_child_redirections(int *pipefd, int prev_pipe_read_end, \
										int current_pipe_write_end, bool is_last);
void			execute_child_command(shell_line_t *cmd_node, data_t *d);
void			handle_parent_pipes(int *pipefd, int *prev_pipe_read_end, \
									int current_pipe_write_end, bool is_last);
void			wait_for_children(int num_cmds, pid_t *pids, data_t *d);
char			*find_cmd_path_in_exec(const char *cmd, data_t *d);

/* Signals */
void			init_signals();
void			ctrl_c(int sig);


#endif