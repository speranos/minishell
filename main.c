/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abihe <abihe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:43:05 by aoueldma          #+#    #+#             */
/*   									              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_norm(void)
{
	g_params.herdoc_dead = 1;
	close(g_params.inputfd);
	close(0);
	g_params.is_heredoc_running = 0;
	g_params.inputfd = -1;
	g_params.ret = 1;
	ft_putstr_fd("\n", 1);
}

void	sig_handler(int sig_init)
{
	(void) sig_init;
	if (g_params.is_heredoc_running)
		sig_norm();
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

void	ft_inputnorm(char *input, t_parser *data, t_envir *envir, t_envir *exp)
{
	add_history(input);
	data = ft_lexxx(input, envir);
	if (data != NULL)
	{
		//ft_execution(&envir, &exp, data);
		ft_free_parser(data);
	}
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_parser	*data;
	// t_envir		*envir;
	// t_envir		*exp;

	(void)av;
	data = NULL;
	ft_args_check(ac, env, &envir, &exp);
	// signal(SIGQUIT, sig_quit);
	// signal(SIGINT, sig_handler);
	g_params.ret = 0;
	while (1)
	{
		input = readline("ach_tama>$ ");
		if (input)
			ft_inputnorm(input, data, envir, exp);
		else
		{
			printf("exit\n");
			exit(1);
		}
		free(input);
	}
}
