#include "../minishell.h"

int	g_signal;

void	signal_handler(int sig)
{
	if (sig == SIGINT) // Ctrl+C
	{
		if (g_signal == S_CMD) // Si hay un comando en ejecución
		{
			g_signal = S_SIGINT_CMD;
			ft_printf("\n");
		}
		else // Modo normal (shell interactiva)
		{
			g_signal = S_SIGINT;
			ft_printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT) // Ctrl+Backslash
	{
		g_signal = S_SIGINT_CMD;
		ft_printf("Quit: %d\n", sig);
	}
}

void	init_signals()
{
	g_signal = S_BASE;
	signal(SIGINT, signal_handler); // Maneja Ctrl+C
	signal(SIGQUIT, SIG_IGN); // Maneja Ctrl+Backslash
}