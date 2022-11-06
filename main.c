#include "minishell.h"

int main(int ac, char **av, char **env)
{
    // int i;
    (void)av;
    (void)ac;
    (void)env;
    char    *str;
	while(1)
	{
        str = readline("ach_tama> ");
        printf("str ====== %s\n", str);
	}
    // printf("str === %s\n", str);

    // i = 0;
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