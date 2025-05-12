
#include "../minishell.h"

char	*single_quotation_parsing(char *cmd, int index, data_t *d)
{
	char	*temp;
	int		end;

	end = next_end(cmd, 39, index);
	temp = ft_strnndup(cmd, index, end);
	temp = command_expander(temp, d);
	return (temp);
}
