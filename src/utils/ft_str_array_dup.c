#include "../minishell.h"


char	**ft_str_array_dup(char **array)
{
	char	**new_array;
	int		i;
	int		len;

	if (!array)
		return (NULL);
	len = 0;
	while (array[len])
		len++;
	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ((new_array[i] = ft_strdup(array[i])) == NULL)
		{
			array_free(new_array);
			return (NULL);
		}
		i++;
	}
	new_array[len] = NULL;
	return (new_array);
}
