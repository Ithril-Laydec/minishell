#include "../minishell.h"

void	handle_parent_pipes(data_t *d)
{
	if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
		close(d->pipeline.prev_pipe_read_end);
	
	if (!d->pipeline.is_last)
	{
		close(d->pipeline.current_pipe_write_end);
		d->pipeline.prev_pipe_read_end = d->pipeline.pipefd[0];
	}
	else
		d->pipeline.prev_pipe_read_end = STDIN_FILENO;
}
