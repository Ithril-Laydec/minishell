#include "../minishell.h"

static char	*append_str(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*parse_pwd(char *pwd, data_t *d)
{
	char	*home;

	home = ft_getenv("HOME", d);
	if (home && pwd && ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		char	*short_pwd;

		short_pwd = ft_strjoin("~", pwd + ft_strlen(home));
		if (!short_pwd)
			custom_exit(d, "Error: Unable to allocate memory for shortened PWD.", EXIT_FAILURE);
		return (short_pwd);
	}
	if (pwd)
		return (ft_strdup(pwd));
	return (ft_strdup(""));
}

static void	init_prompt_values(data_t *d, char **user, char **pwd)
{
	char	*pwd_path;

	*user = ft_getenv("USER", d);
	pwd_path = ft_getenv("PWD", d);
	if (!*user)
		*user = "user";
	*pwd = parse_pwd(pwd_path, d);
	if (!*pwd)
		custom_exit(d, "Error: Unable to allocate memory for PWD.", EXIT_FAILURE);
}

static char	*build_prompt_colors(char *user, char *pwd)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (!prompt)
		return (NULL);
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
	return (prompt);
}

char	*prompter(data_t *d)
{
	char	*prompt;
	char	*user;
	char	*pwd;

	init_prompt_values(d, &user, &pwd);
	prompt = build_prompt_colors(user, pwd);
	if (!prompt)
	{
		free(pwd);
		custom_exit(d, "Error: Unable to allocate memory for prompt.", EXIT_FAILURE);
	}
	free(pwd);
	return (prompt);
}

