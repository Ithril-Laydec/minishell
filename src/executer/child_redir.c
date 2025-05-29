#include "../minishell.h"

void	setup_child_redirections(data_t *d)
{
	int	next_pipe_read_end;

	if (!d->pipeline.is_last)
	{
		next_pipe_read_end = d->pipeline.pipefd[0];
		close(next_pipe_read_end);
	}
	if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
	{
		if (dup2(d->pipeline.prev_pipe_read_end, STDIN_FILENO) == -1)
		{
			ft_printf("minishell: dup2 stdin: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		close(d->pipeline.prev_pipe_read_end);
	}
	if (d->pipeline.current_pipe_write_end != STDOUT_FILENO)
	{
		if (dup2(d->pipeline.current_pipe_write_end, STDOUT_FILENO) == -1)
		{
			ft_printf("minishell: dup2 stdout: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		close(d->pipeline.current_pipe_write_end);
	}
}
