#include "../minishell.h"

void	setup_child_redirections(int *pipefd, int prev_pipe_read_end, \
								int current_pipe_write_end, bool is_last)
{
	int	next_pipe_read_end;

	if (!is_last)
	{
		next_pipe_read_end = pipefd[0];
		close(next_pipe_read_end);
	}
	if (prev_pipe_read_end != STDIN_FILENO)
	{
		if (dup2(prev_pipe_read_end, STDIN_FILENO) == -1)
		{
			ft_printf("minishell: dup2 stdin: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		close(prev_pipe_read_end);
	}
	if (current_pipe_write_end != STDOUT_FILENO)
	{
		if (dup2(current_pipe_write_end, STDOUT_FILENO) == -1)
		{
			ft_printf("minishell: dup2 stdout: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		close(current_pipe_write_end);
	}

}
