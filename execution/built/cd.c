#include "../../minishell.h"



void	update_PWD(t_envir **env)
{
	t_envir	*tmp;
	char *path;

	tmp = *env;
	path = ft_pwd();
	printf("path = %s",path);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			printf("roma\n");
			if (tmp->value)
				free(tmp->value);
			free(tmp->line_env);
			tmp->line_env = ft_strdup(ft_strjoin("PWD=", path));
			tmp->value = ft_strdup(path);
			free(path);
			return ;
		}
		tmp = tmp->next;
	}
}

void	update_old(t_envir **env)
{
	t_envir	*tmp;
	char *path;

	tmp = *env;
	path = ft_pwd();
	printf("path = %s",path);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "OLDPWD"))
		{
			printf("roma\n");
			if (tmp->value)
				free(tmp->value);
			free(tmp->line_env);
			tmp->line_env = ft_strdup(ft_strjoin("OLDPWD=", path));
			tmp->value = ft_strdup(path);
			free(path);
			return ;
		}
		tmp = tmp->next;
	}
}


void	ft_cd(char *argv, t_envir **env, t_envir **exp)
{
	(void)exp;
	if (!chdir(argv))
	{
		update_PWD(env);
		update_PWD(exp);
	}
}