/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:55 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 15:53:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* char	**double_quotes(char *str, int dollar);	*/

char	*single_quotes(char *str, int *index)
{
	char	*temp;
	int		start;

	start = *index;
	if (str[*index] == 34)
	{
		(*index)++;
		while (str[*index] && str[*index] != 34)
			(*index)++;
	}
	temp = ft_substr(str, start + 1, *index - start - 1);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	return (temp);
}

char	*double_quotes(char *str, int *index)
{
	char	*temp;
	int		start;

	start = *index;
	if (str[*index] == 34)
	{
		(*index)++;
		while (str[*index] && str[*index] != 34)
			(*index)++;
	}
	temp = ft_substr(str, start + 1, *index - start - 1);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	if (is_there_dollars(str))
	{
		temp = expand_argv(temp, index);
		if (!temp)
		{
			free(str);
			return (NULL);
		}
	}
	return (temp);
}

char	*parsing_quotes(char *str, int *start)
{
	char	*temp;
	char	*parse;
	int		index;

	index = 0;
	parse = NULL;
	while (str[*start])
	{
		if (str[*start] == 34)
			temp = double_quotes(str, start);
		else if (str[*start] == 39)
			temp = single_quotes(str, start);
		ft_strjoin(parse, temp);
		if (!parse)
		{
			free(str);
			return (NULL);
		}
	}
	return (parse);
}

char	**parsing(char *argv)
{
	char	*str;
	char	*temp;
	int		index;

	str = ft_strtrim(argv, " ");
	if (!str)
		return (NULL);
	temp = NULL;
	index = 0;
	while (str[index])
	{
		if (is_there_quotes(str))
		{
			index++;
			temp = parsing_quotes(str, &index);
		}
		else
		{
			temp = ft_strjoin(temp, expand_argv(str, &index));
			if (!temp)
				return (NULL);
		}
	}
	return (to_split(temp, str));
}

char	**pre_parsing(char *argv)
{
	char	**cmd;
	int		index;

	if (is_there_quotes(argv) == 0)
	{
		index = 0;
		return (no_quotes_expand(argv, is_there_dollars(argv)));
	}
	cmd = parsing(argv);
	if (!cmd)
		return (NULL);
	/* if (checking_content(cmd) == 0)
	{
		free_cmd(cmd)
		return (NULL);
	}	*/
	return (cmd);
}

int	main(int argc, char **argv)
{
	char	**cmd;
	int		yndex;

	if (argc != 2)
		return (0);
	cmd = pre_parsing(argv[1]);
	yndex = 0;
	while (cmd[yndex])
	{
		printf("%s\n", cmd[yndex]);
		yndex++;
	}
	return (0);
}
