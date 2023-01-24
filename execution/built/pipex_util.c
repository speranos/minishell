#include "../../minishell.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		d;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i + 1 < n)
	i++;
	d = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (!d || !n)
		return (0);
	else if (d < 0)
		return (-1);
	else
		return (1);
}

char	**sear_path(t_envir **env)
{
	int		i;
	t_envir	*tmp;

	i = 0;
	tmp = *env;
	while (tmp && ft_strncmp(tmp->name, "PATH", 4))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (ft_split(tmp->value, ':'));
}

char	*set_path(t_envir **env, char *cmd)
{
	char	**path;
	char	*str;
	t_envir	*tmp;
	int		i;

	i = 0;
	tmp = *env;
	path = sear_path(&tmp);
	if (!path)
		return (cmd);
	while (path[i])
	{
		str = ft_strjoin("/", cmd);
		path[i] = ft_strjoin(path[i], str);
		free(str);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (cmd);
}

// void	exec_env(t_envir **env, t_pip *pip)
// {
// 	int		i;
// 	t_envir	*tmp;
// 	i = 0;
// 	tmp = *env;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	pip->env = malloc(sizeof(char *) * (i + 1));
// 	i = 0;
// 	while (tmp)
// 	{
// 		pip->env[i] = ft_strdup(tmp->line_env);
// 		tmp = tmp->next;
// 		printf("heroshima=====>>> %s\n", pip->env[i]);
// 		i++;
// 	}
// 	pip->env[i] = 0;
// }

t_pip	*ft_fil_pip(t_pip *pip, t_parser *data)
{
	int	i = 0;

	pip = malloc(sizeof(t_pip));
	pip->nb_pip = size_list(data) - 1;
	pip->fd = malloc(sizeof(int*) * pip->nb_pip);
	while (i < pip->nb_pip)
	{
		pip->fd[i] = malloc(sizeof(int) * 2);
		pipe(pip->fd[i]);
		i++;
	}
	return (pip);
 }