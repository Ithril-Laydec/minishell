#include "../minishell.h"

void	pwd()
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		return;
	}
	ft_printf("%s\n", pwd);
	free(pwd);
}