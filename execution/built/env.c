/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:08:25 by abihe             #+#    #+#             */
/*   Updated: 2023/01/24 15:25:40 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_copy_env(char **env, t_envir **envir)
{
	int	i;

	i = 1;
	(*envir) = ft_lstnew(env[0]);
	while (env[i])
	{
		ft_add_ba(envir, ft_lstnew(env[i]));
		i++;
	}
}

void	ft_env_printf(t_envir *env, int fd)
{
	if(!env)
	{
		ft_error("minishell: ", "env:", " No such file or directory\n", 127);
		return ;
	}
	while (env)
	{
		ft_putstr_fd(env->line_env, fd);
		ft_putstr_fd("\n", fd);
		env = env->next;
	}
}
