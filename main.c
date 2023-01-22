/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:43:05 by aoueldma          #+#    #+#             */
/*   Updated: 2023/01/22 17:26:32 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_intro(void)
{
	printf("\n\n\t\t\t\t\t\\\\\\\\ WELCOME TO MINISHELL //// \n\n");
}

//l_clear_history, rl_on_new_line,
//rl_replace_line, rl_redisplay,

/*
void    sig_handler(int signum)
{
    if (signum == SIGINT && !g_var.sig)
    {
        g_var.exit_code = 1;
        write (1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    if (signum == SIGINT && g_var.sig == 1)
    {
        write (1, "\n", 1);
    }
    if (signum == SIGINT && g_var.                                                    == 2)
    {
        g_var.exit_code = 1;
        g_var.herdoc_flag = 0;
        close (0);
        write (1, "\n", 1);
    }
}*/

// void	sig_handler(int sig_init)
// {
// 	(void)sig_init;
// 	write (1, "\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }
// void	sig_handler(int sig_init)
// {
// 	sig_init = 0;
// 	exit(0);
// }

void	init_env(t_envir **env, t_envir **exp)
{
	env = NULL;
	exp = NULL;

	env = malloc(sizeof(t_envir));
	exp = malloc(sizeof(t_envir));
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
	signal(SIGQUIT, SIG_IGN);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_parser	*data;
	t_envir		*envir;
	t_envir		*exp;

	(void)av;
	ft_args_check(ac, env, &envir, &exp);
	signal(SIGQUIT, SIG_IGN);
	// signal(SIGINT, sig_handler);
	while (1)
	{
		input = readline("ach_tama>$ ");
		if (input)
		{
			add_history(input);
			data = ft_lexxx(input);
			if (data != NULL)
			{
				ft_execution(&envir, &exp, data);
				ft_free_parser(data);
			}
		}
		else
		{
			write(2, "exit\n", 6);
			exit(1);
		}
		free(input);
	}
}
