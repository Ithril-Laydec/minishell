
#include "../minishell.h"

char	*double_quotation_parsing(char *cmd, int index, data_t *d)
{
	char	*temp;
	int		end;

	end = next_end(cmd, 34, index);
	temp = ft_strnndup(cmd, index, end);
	if (temp[0] == 36)
		temp = ft_getenv(ft_strnndup(temp, 1, '\0'), d);
	temp = command_expander(temp, d);
	return (temp);
}
