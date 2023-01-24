/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:43:45 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 22:46:25 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_pwd(t_envir **env)
{
	t_envir	*tmp;
	char	*path;
	int		fd;

	fd = 1;
	tmp = *env;
	path = ft_pwd(*env);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
		{
			if (tmp->value)
				free(tmp->value);
			free(tmp->line_env);
			tmp->line_env = ft_strjoin("PWD=", path);
			tmp->value = ft_strdup(path);
			free(path);
			return ;
		}
		tmp = tmp->next;
	}
	free(tmp);
}

void	ft_cd(char *argv, t_envir **env, t_envir **exp)
{
	if (!chdir(argv))
	{
		update_pwd(env);
		update_pwd(exp);
	}
	else
	{
		printf("minishell: cd: %s No such file or directory", argv);
	}
}
