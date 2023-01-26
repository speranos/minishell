/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:43:05 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/26 04:00:37 by abihe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_intro(void)
{
	printf("\n\n\t\t\t\t\t\\\\\\\\ WELCOME TO MINISHELL //// \n\n");
}

void	sig_handler(int sig_init)
{
	(void) sig_init;
	if (g_params.is_heredoc_running)
	{
		close(g_params.inputfd);
		g_params.is_heredoc_running = 0;
		g_params.inputfd = -1;
		g_params.ret = 1;
		ft_putstr_fd("\n", 1);
	}
	else
	{
		if (g_params.is_process_running == 1)
		{
			g_params.ret = 130;
			ft_putstr_fd("\n", 1);
		}
		else
		{
			g_params.ret = 1;
			ft_putstr_fd("\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}

void	sig_quit(int sig_init)
{
	(void) sig_init;
	if (g_params.is_process_running)
	{
		g_params.ret = 131;
		ft_putstr_fd("Quit: 3\n", 1);
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	init_env(t_envir **env, t_envir **exp)
{
	env = NULL;
	exp = NULL;
}

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

void	ft_inputnorm(char *input, t_parser *data, t_envir *envir, t_envir *exp)
{
	add_history(input);
	data = ft_lexxx(input);
	if (data != NULL)
	{
		ft_execution(&envir, &exp, data);
		ft_free_parser(data);
	}
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_parser	*data;
	t_envir		*envir;
	t_envir		*exp;

	(void)av;
	data = NULL;
	ft_args_check(ac, env, &envir, &exp);
	signal(SIGQUIT, sig_quit);
	signal(SIGINT, sig_handler);
	g_params.ret = 0;
	while (1)
	{
		input = readline("ach_tama>$ ");
		if (input)
			ft_inputnorm(input, data, envir, exp);
		else
		{
			write(2, "exit\n", 6);
			exit(1);
		}
		free(input);
	}
}
