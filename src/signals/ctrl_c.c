#include "../minishell.h"

void	ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line(); 
		rl_replace_line("", 0); 
		rl_redisplay();
	}
}