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

int main(int ac, char **av, char **env)
{
	char    	*input;
	// t_parser	*daaaaa;
	t_token		*link = NULL;

	ft_init(link);
	ft_args_check(ac, av, env);
	ft_intro();
	while(1)
	{
		input = readline("ach_tama>$ ");
		if(*input != '\0')
		{
			add_history(input);
			ft_lexxx(input, link);
		}
		free(input);
	}
}

void	ft_init(t_token *link)
{
	link = NULL;
	exit_error = 45678978;
}