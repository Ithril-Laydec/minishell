#include "../minishell.h"

pid_t	fork_process(data_t *d)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid == -1)
	{
		if (!d->pipeline.is_last)
		{
			close(d->pipeline.pipefd[0]);
			close(d->pipeline.pipefd[1]);
		}
		if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
			close(d->pipeline.prev_pipe_read_end);
		i = d->pipeline.cmd_index;
		while (--i >= 0)
			waitpid(d->pipeline.pids[i], NULL, 0);
		free(d->pipeline.pids);
		custom_exit(d, "fork failed", EXIT_FAILURE);
	}
	return (pid);
}

void	create_pipe_if_needed(data_t *d)
{
	d->pipeline.current_pipe_write_end = STDOUT_FILENO;
	if (!d->pipeline.is_last)
	{
		if (pipe(d->pipeline.pipefd) == -1)
		{
			free(d->pipeline.pids);
			if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
				close(d->pipeline.prev_pipe_read_end);
			custom_exit(d, "pipe failed", EXIT_FAILURE);
		}
		d->pipeline.current_pipe_write_end = d->pipeline.pipefd[1];
	}
}

int	execute_pipeline(data_t *d)
{
	pid_t	pid;

	d->pipeline.cmd_index = 0;
	d->pipeline.prev_pipe_read_end = STDIN_FILENO;
	d->pipeline.current_cmd = d->sh_ln;

	while (d->pipeline.current_cmd)
	{
		d->pipeline.is_last = (d->pipeline.current_cmd->next == NULL);
		create_pipe_if_needed(d);
		
		pid = fork_process(d);
		
		if (pid == 0)
		{
			setup_child_redirections(d);
			execute_child_command(d->pipeline.current_cmd, d);
		}
		else
		{
			d->pipeline.pids[d->pipeline.cmd_index] = pid;
			handle_parent_pipes(d);
		}
		
		d->pipeline.current_cmd = d->pipeline.current_cmd->next;
		d->pipeline.cmd_index++;
	}
	return (0);
}
