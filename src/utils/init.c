#include "../minishell.h"

static envs_t	*parse_env(char **envs, data_t *d)
{
	envs_t	*head;
	envs_t	*tmp;
	envs_t	*last;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	head = NULL;
	while (envs[i])
	{
		tmp = salloc(sizeof(envs_t), d);
		tmp->next = NULL;
		len = 0;
		while(envs[i][len] && envs[i][len] != '=')
			len++;
		tmp->name = salloc(len + 1, d);
		j = 0;
		while(j < len)
		{
			tmp->name[j] = envs[i][j];
			j++;
		}
		tmp->name[j] = '\0';
		j++;
		len = 0;
		while(envs[i][j + len] && envs[i][j + len] != '\0')
			len++;
		k = 0;
		tmp->value = salloc(len + 1, d);
		while(k < len)
		{
			tmp->value[k] = envs[i][j + k];
			k++;
		}
		tmp->value[k] = '\0';
		if (head == NULL)
		{
			head = tmp;
			last = tmp;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
		i++;
	}
	// i = 0;
	// tmp = head;
	// while (tmp)
	// {
	// 	printf("envs[%d]: %s=%s\n", i, tmp->name, tmp->value);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	return (head);
}

void	init_data(data_t **d, char **envs)
{
	*d = salloc(sizeof(data_t), NULL);
	(*d)->envs = parse_env(envs, *d);
	(*d)->sh_ln = NULL;
	(*d)->user = NULL;
	(*d)->pwd = NULL;
}