#include "../minishell.h"

void	handle_parent_pipes(int *pipefd, int *prev_pipe_read_end, \
							int current_pipe_write_end, bool is_last)
{
	if (*prev_pipe_read_end != STDIN_FILENO)
		close(*prev_pipe_read_end);
	if (!is_last)
	{
		close(current_pipe_write_end);
		*prev_pipe_read_end = pipefd[0];
	}
	else
		*prev_pipe_read_end = STDIN_FILENO;
}
