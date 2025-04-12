#include "../minishell.h"

static envs_t	*parse_env(char **envs, data_t *d)
{
	envs_t	*head;
	envs_t	*tmp;
	int		i;
	int		j;

	i = 0;
	head = NULL;
	while (envs[i])
	{
		tmp = salloc(sizeof(envs_t), d);
		tmp->next = NULL;
		j = 0;
		while(envs[i][j] && envs[i][j] != '=')
		j++;
		tmp->name = salloc(j + 1, d);
		ft_strncpy(tmp->name, envs[i], j);
		tmp->value = salloc(ft_strlen(envs[i]) - j + 1, d);
		ft_strncpy(tmp->value, envs[i] + j + 1, ft_strlen(envs[i]) - j);
		ft_lstadd_back((t_list **)&head, (t_list *)tmp);
		printf("envs:\n");
		i++;

	}
	i = 0;
	tmp = head;
	while (tmp)
	{
		printf("envs[%d]: %s=%s\n", i, tmp->name, tmp->value);
		tmp = tmp->next;
		i++;
	}
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