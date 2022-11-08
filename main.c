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
    printf(" _________________________ \\\\\\\\ WELCOME TO MINISHELL ////  _________________________ \n");
}

int main(int ac, char **av, char **env)
{
    char    *input;
    ft_args_check(ac, av, env);
    ft_intro();
	while(1)
	{
        input = readline("ach_tama>$ ");
		if(*input != '\0')
		{
			add_history(input);
            ft_lexxx(input);
		}

	}
}