#include "../minishell.h"

char *parse_pwd(char *pwd, data_t *d)
{
	char *home;

	home = ft_getenv("HOME", d);
	if (home && ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		char *short_pwd = ft_strjoin("~", pwd + ft_strlen(home));
		if (!short_pwd)
			error(d, "Error: Unable to allocate memory for shortened PWD.");
		return short_pwd;
	}
	return ft_strdup(pwd);
}

char	*prompter(data_t *d)
{
	char *prompt;

	d->user = ft_getenv("USER", d);
	d->pwd = parse_pwd(ft_getenv("PWD", d), d);
	if (d->user == NULL || d->pwd == NULL)
		error(d, "Error: Unable to get environment variables.");
	prompt = ft_strdup("");
	if (prompt == NULL)
		error(d, "Error: Unable to allocate memory for prompt.");
	//TODO: arreglar fugas
	prompt = ft_strjoin(prompt, "\001\033[35m\002");
	prompt = ft_strjoin(prompt, d->user);
	prompt = ft_strjoin(prompt, "\001\033[34m@\002");
	prompt = ft_strjoin(prompt, "\001\033[33m\002");
	prompt = ft_strjoin(prompt, "Shellder");
	prompt = ft_strjoin(prompt, "\001\033[37m\002");
	prompt = ft_strjoin(prompt, "\001\033[1;32m\002");
	prompt = ft_strjoin(prompt, ": ");
	prompt = ft_strjoin(prompt, d->pwd);
	prompt = ft_strjoin(prompt, "$> ");
	prompt = ft_strjoin(prompt, "\001\033[0m\002");
	return (prompt);
}

