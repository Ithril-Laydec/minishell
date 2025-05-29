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
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>

extern int	g_signal;

/* 
	S_BASE: Base signal
	S_HEREDOC: Entering heredoc
	S_HEREDOC_END: End of heredoc
	S_SIGINT: Ctrl + C
	S_SIGINT_CMD: Ctrl + C in the middle of a command
	S_CMD: Executing a command
	S_CANCEL_EXEC: Ctrl + D in heredoc
*/
typedef enum e_signal
{
	S_BASE,
	S_HEREDOC,
	S_HEREDOC_END,
	S_SIGINT,
	S_SIGINT_CMD,
	S_CMD,
	S_CANCEL_EXEC,
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
	struct s_envs		*next;
}						envs_t;

typedef struct s_pipeline
{
	int					pipefd[2];
	int					prev_pipe_read_end;
	int					current_pipe_write_end;
	int					is_last;
	pid_t				*pids;
	int					cmd_count;
	int					cmd_index;
	shell_line_t		*current_cmd;
}						t_pipeline;

typedef struct s_data
{
	char				*line;
	struct s_shell_line	*sh_ln;
	char				**str_env;
	struct s_envs		*envs; // Lista enlazada para el export
	int					exit_status;
	char				*prompt;
	t_pipeline			pipeline;
}						data_t;

/* Utils */
void			init_data(data_t **d, char **env);
char			**ft_str_array_dup(char **array);
void			free_data(data_t *d);
char			*ft_getenv(char *name, data_t *d);
void			ft_setenv(char *name, char *value, data_t *d);
char			*prompter(data_t *d);
void			free_shell_line(shell_line_t *sh_ln);

/* Secure Alloc, forces etix if malloc fails */
void			*salloc(size_t size, data_t *d);

/* Print an error and exit */
void			custom_exit(data_t *d, char *msg, int exit_code);

/* Parser */
shell_line_t	*command_node(char *line, data_t *d);
shell_line_t	*command_struct(char *line, data_t *d);
char			*parsing(char *str, data_t *d);
char			*no_quotes_expand(char *str, data_t *d);
char			*process_env_variable(data_t *d, char *expanded, char *str, int *index);
char			*continue_expand(char *expanded, char c);
char			*parsing_continue(char	*argv);
char			*parsing_double_quote(char *argv, int *index, char *result);
char			*parsing_single_quote(char *argv, int *index, char *result);
char			*parsing_text(char *argv, int *index, char *result);
int				is_there_quotes(char *str);
int				is_there_dollars(char *str);
int				is_space(char c);
int				no_space_finder(char *str);
int				flag_calculator(char *line, int index, int quote);
int				parsing_count_words(char const *s, char c);
char			**parsing_split(char const *s, char c);
void			*array_free(char **array);
char			*ft_strndup(const char *str, int init);

/* Buildt-ins */
void			print_ascii_art(const char *filename);
void			echo(char **cmd);
void			cd(data_t *d);
void			pwd(void);
void			export(data_t *d);
void			unset(data_t *d);
void			env(data_t *d);
void			exit_shell(data_t *d);

/* CD utils */
void			update_pwd_vars(data_t *d);

/* Envs */
void			ft_setenv(char *name, char *value, data_t *d);
void			ft_unsetenv(char *name, data_t *d);
void			sort_envs(data_t *d);

/* Executer */
void			loop(data_t *d);
void			executer(data_t *d);
int				is_builtin(const char *cmd);
int				execute_builtin(data_t *d);
int				handle_single_parent_buildin(data_t *d);
int				execute_pipeline(data_t *d);
void			setup_child_redirections(data_t *d);
void			execute_child_command(shell_line_t *cmd_node, data_t *d);
void			handle_parent_pipes(data_t *d);
void			wait_for_children(data_t *d);
char			*find_cmd_path_in_exec(const char *cmd, data_t *d);
pid_t			fork_process(data_t *d);
void			create_pipe_if_needed(data_t *d);

/* Signals */
void			init_signals();
void			ctrl_c(int sig);



#endif