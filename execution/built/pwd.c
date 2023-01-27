/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:39:09 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 21:21:53 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env(char *var, t_envir *env)
{
	char	*ret;

	ret = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, var) == 0)
			ret = ft_strdup(env->value);
		env = env->next;
	}
	if (ret)
		return (ret);
	return (ft_strdup(""));
}

char	*ft_pwd(t_envir *env)
{
	char	pwd[1024];
	char	*path;

	if (getcwd(pwd, 1024))
	{
		path = ft_strdup(pwd);
		return (path);
	}
	return (get_env("PWD", env));
}

int	is_built(t_parser *tmp)
{
	if (!ft_strcmp(tmp->args[0], "pwd"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "echo"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "cd"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "exit"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "env"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "unset"))
		return (0);
	else if (!ft_strcmp(tmp->args[0], "export"))
		return (0);
	else
		return (1);
}

int	size_list(t_parser *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	red_0(t_parser *data, int fdin)
{
	fdin = open(data->redi->fname, O_RDONLY);
	if (fdin < 0)
	{
		printf("Minishell: %s:  No such file or directory\n", data->redi->fname);
		exit (1);
	}
	dup2(fdin, 0);
	close(fdin);
}
