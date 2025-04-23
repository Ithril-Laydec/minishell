#include "../minishell.h"

void	exit_shell(data_t *d)
{
	free_data(d);
	exit(EXIT_SUCCESS);
}