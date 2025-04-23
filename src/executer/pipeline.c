#include "../minishell.h"

static pid_t	fork_process(data_t *d, int i, pid_t *pids, int *pipefd, \
							int prev_pipe_read_end, bool is_last)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		if (!is_last)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		if (prev_pipe_read_end != STDIN_FILENO)
			close(prev_pipe_read_end);
		while (--i >= 0)
			waitpid(pids[i], NULL, 0);
		free(pids);
		error(d, "fork failed");
	}
	return (pid);
}

static int	create_pipe_if_needed(bool is_last, int *pipefd, data_t *d, \
								int prev_pipe_read_end, pid_t *pids)
{
	int	current_pipe_write_end;

	current_pipe_write_end = STDOUT_FILENO;
	if (!is_last)
	{
		if (pipe(pipefd) == -1)
		{
			free(pids);
			if (prev_pipe_read_end != STDIN_FILENO)
				close(prev_pipe_read_end);
			error(d, "pipe failed");
		}
		current_pipe_write_end = pipefd[1];
	}
	return (current_pipe_write_end);
}

int	execute_pipeline(data_t *d, int num_cmds, pid_t *pids)
{
	int				i;
	int				pipefd[2];
	int				prev_pipe_read_end;
	int				current_pipe_write_end;
	shell_line_t	*current_cmd;
	pid_t			pid;
	bool			is_last;

	i = 0;
	prev_pipe_read_end = STDIN_FILENO;
	current_cmd = d->sh_ln;
	while (current_cmd)
	{
		is_last = (current_cmd->next == NULL);
		current_pipe_write_end = create_pipe_if_needed(is_last, pipefd, d, \
													prev_pipe_read_end, pids);
		pid = fork_process(d, i, pids, pipefd, prev_pipe_read_end, is_last);
		if (pid == 0)
		{
			setup_child_redirections(pipefd, prev_pipe_read_end, \
									current_pipe_write_end, is_last);
			execute_child_command(current_cmd, d);
		}
		else
		{
			pids[i] = pid;
			handle_parent_pipes(pipefd, &prev_pipe_read_end, \
								current_pipe_write_end, is_last);
		}
		current_cmd = current_cmd->next;
		i++;
	}
	return (0);
}
