/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:39:09 by abihe             #+#    #+#             */
/*   Updated: 2023/01/26 02:57:26 by abihe            ###   ########.fr       */
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
