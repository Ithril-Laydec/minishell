#include "../minishell.h"

void print_ascii_art(const char *filename)
{
	int fd;
	char buffer[1024];
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return;
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		ft_printf("%s", buffer);
	}
	close(fd);
}
