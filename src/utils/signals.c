#include "../minishell.h"

int	g_signal;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_signal == S_CMD)
		{
			g_signal = S_SIGINT_CMD;
			ft_printf("\n");
		}
		else
		{
			g_signal = S_SIGINT;
			ft_printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT)
	{
		g_signal = S_SIGINT_CMD;
		ft_printf("Quit: %d\n", sig);
	}
}

void	init_signals()
{
	g_signal = S_BASE;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
