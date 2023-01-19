/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:08:25 by abihe             #+#    #+#             */
/*   Updated: 2023/01/19 18:04:33 by abihe            ###   ########.fr       */
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
	while(env)
	{
		ft_putstr_fd(env->line_env, fd);
		ft_putstr_fd("\n", fd);
		// printf("%s\n", env->line_env);
		env = env->next;
	}
}
