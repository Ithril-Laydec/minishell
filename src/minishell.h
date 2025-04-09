

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>



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

typedef struct s_data
{
	struct s_shell_line	*shell_line;
	char				**envs;

}						data_t;

/* Utils */
void			init_data(data_t **d, char **env);
void			free_data(data_t *d);
void			error(data_t *d, char *msg);

/* Executer */
void			executer(shell_line_t *shell_line);



#endif