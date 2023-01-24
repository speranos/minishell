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

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*set_path(t_envir **env, char *cmd)
{
	char	**path;
	char	*str;
	char	*pt;
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
		pt = ft_strjoin(path[i], str);
		free(str);
		if (access(pt, F_OK) == 0)
		{
			free_double(path);
			// free(path);
			return (pt);
		}
		else
		{
			// free(path[i]);
			free(pt);
		}
		i++;
	}
	if (path)
		free_double(path);
	return (cmd);
}