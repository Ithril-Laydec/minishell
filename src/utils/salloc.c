#include "../minishell.h"

void	*salloc(size_t size, data_t *d)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		custom_exit(d, "Error: Memory allocation failed", EXIT_FAILURE);
	return (ptr);
}