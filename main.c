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
    char    *str;
    ft_args_check(ac, av, env);
    ft_intro();
	while(1)
	{
        str = readline("ach_tama> ");
        printf("str ====== %s\n", str);
	}
    // while(env[i])
    // {
    //     printf("HOla comista do\n");
    //     printf("env == %s\n", env[1]);
    //     i++;
    // }
}

// #include <signal.h>
// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <unistd.h>
// #include <stdlib.h>

// void handler(int signum)
// {
//     if (signum != SIGINT)
//         return;
//     printf("ctrl + c\n");
//     rl_on_new_line();
//     rl_replace_line("", 1);
//     rl_redisplay();
// }

// int main(void)
// {
//     int ret = 0;
//     char *line;

//     signal(SIGINT, handler);
//     while (1)
//     {
//         line = readline("input> ");
//         if (line)
//         {
//             if (ret)
//                 printf("output> %s\n", line);
//             add_history(line);
//             free(line);
//             line = NULL;
//         }
//         else
//         {
//             printf("ctrl + d\n");
//         }
//     }
//     return (0);
// }