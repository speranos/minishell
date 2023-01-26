/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inv_and_arg_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:54:39 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 15:54:43 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_args_check(int ac, char **env, t_envir **envir, t_envir **exp)
{
	if (ac != 1)
	{
		printf("arg...error!!!\nprogram...exit...byye!!!\n");
		exit(0);
	}
	ft_intro();
	init_env(envir, exp);
	ft_copy_env(env, envir);
	ft_copy_env(env, exp);
}

void	ft_intro(void)
{
	printf("\n\n\t\t\t\t\t\\\\\\\\ WELCOME TO MINISHELL //// \n\n");
}

void	init_env(t_envir **env, t_envir **exp)
{
	env = NULL;
	exp = NULL;
}
