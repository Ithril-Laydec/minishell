#include "../minishell.h"

void	init_data(data_t **d, char **envs)
{
	*d = salloc(sizeof(data_t), NULL);
	(*d)->envs = envs;
	(*d)->sh_ln = NULL;
	(*d)->user = NULL;
	// (*d)->host = NULL;
	(*d)->pwd = NULL;
}