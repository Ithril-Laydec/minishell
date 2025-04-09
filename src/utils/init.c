#include "../minishell.h"

void	init_data(data_t **d, char **env)
{
	*d = malloc(sizeof(data_t));
	if (*d == NULL)
		error(d, "malloc");
	(*d)->shell_line = NULL;
	(*d)->envs = env;
}