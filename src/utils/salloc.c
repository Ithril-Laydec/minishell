#include "../minishell.h"

void	*salloc(size_t size, data_t *d)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		error(d, "Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}