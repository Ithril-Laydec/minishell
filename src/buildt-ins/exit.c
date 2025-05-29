#include "../minishell.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	extract_number(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((num * sign) & 0xFF);
}

void	exit_shell(data_t *d)
{
	int	exit_code;

	ft_printf("exit\n");
	if (d->sh_ln->cmd[1])
	{
		if (d->sh_ln->cmd[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			d->exit_status = 1;
			return;
		}
		if (!is_valid_number(d->sh_ln->cmd[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(d->sh_ln->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			free_data(d);
			exit(2);
		}
		exit_code = extract_number(d->sh_ln->cmd[1]);
		free_data(d);
		exit(exit_code);
	}
	free_data(d);
	exit(d->exit_status);
}