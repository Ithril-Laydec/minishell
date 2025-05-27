#include "../minishell.h"

char *append_str(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char *parse_pwd(char *pwd, data_t *d)
{
	char *home;

	home = ft_getenv("HOME", d);
	if (home && ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		char *short_pwd = ft_strjoin("~", pwd + ft_strlen(home));
		if (!short_pwd)
			custom_exit(d, "Error: Unable to allocate memory for shortened PWD.", EXIT_FAILURE);
		return short_pwd;
	}
	return ft_strdup(pwd);
}

char	*prompter(data_t *d)
{
	char *prompt;
	char *user;
	char *pwd_path;
	char *pwd;

	user = ft_getenv("USER", d);
	pwd_path = ft_getenv("PWD", d);
	pwd = parse_pwd(pwd_path, d);
	if (user == NULL || pwd == NULL)
		custom_exit(d, "Error: Unable to get environment variables.", EXIT_FAILURE);
	prompt = ft_strdup("");
	if (prompt == NULL)
	{
		free(pwd);
		custom_exit(d, "Error: Unable to allocate memory for prompt.", EXIT_FAILURE);
	}
	prompt = append_str(prompt, "\001\033[35m\002");
	prompt = append_str(prompt, user);
	prompt = append_str(prompt, "\001\033[34m@\002");
	prompt = append_str(prompt, "\001\033[33m\002");
	prompt = append_str(prompt, "Shellder");
	prompt = append_str(prompt, "\001\033[37m\002");
	prompt = append_str(prompt, "\001\033[1;32m\002");
	prompt = append_str(prompt, ": ");
	prompt = append_str(prompt, pwd);
	prompt = append_str(prompt, "$> ");
	prompt = append_str(prompt, "\001\033[0m\002");
	free(pwd);
	return (prompt);
}

