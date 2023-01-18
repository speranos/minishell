#include "minishell.h"

void    ft_args_check(int ac, char **av, char **env)
{
	(void)av;
	(void)env;
	if(ac != 1)
	{
		printf("arg...error!!!\nprogram...exit...byye!!!\n");
		exit(0);
	}
}
void    ft_intro(void)
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
    if (signum == SIGINT && g_var.sig == 2)
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

int main(int ac, char **av, char **env)
{
	char    	*input;
	t_parser	*data;

	ft_args_check(ac, av, env);
	ft_intro();
	//  signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while(1)
	{
		input = readline("ach_tama>$ ");
		if (!input)
			exit (0);
		if(*input != '\0')
		{
			add_history(input);
			data = ft_lexxx(input);
			if(data != NULL)
			{
				ft_print(data);
				ft_free_parser(data);	
			}
			//exec();
		}
		free(input);
	}
}