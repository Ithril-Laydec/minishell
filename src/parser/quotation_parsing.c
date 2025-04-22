
#include "../minishell.h"
#include "parser.h"

/*
echo $HOME
echo /home/aterneto


echo "$HOME"
echo /home/aterneto

echo '$HOME'
echo '$HOME'

echo "'$HOME'"
echo '/home/aterneto'

echo '"$HOME"'
echo "$HOME"
*/

char	*double_inverted_commas(char *line, data_t *d)
{
	char	*temp;
	int		counter;
	int		index;

	index = 0;
	while (line[index] != 36 && line[index] != '\0')
	{
		temp[index] = line[index];
		index++;
	}
	if (line[index] == '$')
		temp = ft_strjoin(temp, ft_getenv(line, d));
	while (line[index])
	{
		if (line[index] == 34)
		{
			if (line[index + 1] == 34);
			else if (line[index + 1] == 36);
			else if (line[index + 1] == 39);
			else
				write(1, &line[index], 1);
		}
		index++;
	}
}

char	*single_inverted_commas(char *line, data_t *d)
{
	return (line);
}

char	*dollar_memmory_address(char *line, data_t *d)
{
	char	*temp;
	int		index;

	index = 0;
	while (line[index] != 36)
	{
		temp[index] = line[index];
		index++;
	}
	if (line[index] == '$')
		temp = ft_strjoin(temp, ft_getenv(line, d));
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (temp);
}

char	*command_expander(char *line, data_t *d)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 36)
			line = dollar_memory_address(line, d);
		else if (line[index] == 34)
		{
			if (char_counter(line, 34) % 2 != 0)
				printf("NOTE: IMPAR.\n");
			line = double_inverted_commas(line, d);
		}
		else if (line[index] == 39)
		{
			if (char_counter(line, 34) % 2 != 0)
				printf("NOTE: IMPAR.\n");
			line = single_inverted_commas(line, d);
		}
	}
}

/*
	ASCII DISCLAMER:
		* 36 == $
		* 34 == "
		* 39 == '
*/