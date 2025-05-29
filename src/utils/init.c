#include "../minishell.h"

static char	*extract_env_name(char *env_string, data_t *d)
{
	int		len;
	int		j;
	char	*name;

	len = 0;
	while (env_string[len] && env_string[len] != '=')
		len++;
	name = salloc(len + 1, d);
	j = 0;
	while (j < len)
	{
		name[j] = env_string[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

static char	*extract_env_value(char *env_string, int name_len, data_t *d)
{
	int		value_len;
	int		j;
	int		k;
	char	*value;

	j = name_len + 1;
	value_len = 0;
	while (env_string[j + value_len] && env_string[j + value_len] != '\0')
		value_len++;
	value = salloc(value_len + 1, d);
	k = 0;
	while (k < value_len)
	{
		value[k] = env_string[j + k];
		k++;
	}
	value[k] = '\0';
	return (value);
}

static envs_t	*create_env_node(char *env_string, data_t *d)
{
	envs_t	*tmp;
	int		name_len;

	tmp = salloc(sizeof(envs_t), d);
	tmp->next = NULL;
	tmp->name = extract_env_name(env_string, d);
	name_len = 0;
	while (env_string[name_len] && env_string[name_len] != '=')
		name_len++;
	tmp->value = extract_env_value(env_string, name_len, d);
	return (tmp);
}

static envs_t	*parse_env(char **envs, data_t *d)
{
	envs_t	*head;
	envs_t	*tmp;
	envs_t	*last;
	int		i;

	i = 0;
	head = NULL;
	while (envs[i])
	{
		tmp = create_env_node(envs[i], d);
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
	return (head);
}

void	init_data(data_t **d, char **envs)
{
	*d = salloc(sizeof(data_t), NULL);
	(*d)->str_env = ft_str_array_dup(envs);	
	(*d)->envs = parse_env(envs, *d);
	(*d)->sh_ln = NULL;
	(*d)->line = NULL;
	(*d)->exit_status = 0;
	(*d)->prompt = NULL;
}
