#include "../minishell.h"

void	custom_exit(data_t *d, char *msg, int exit_code)
{
	free_data(d);
	if (msg != NULL)
		ft_printf("%s", msg);
	exit(exit_code);
}
