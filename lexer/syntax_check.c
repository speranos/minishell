#include "../minishell.h"

void    ft_syntax_check(t_token *link)
{
    (void)link;
}

void	ft_print(t_token *link)
{
    	while(link != NULL)
	{
		printf("token(%d, %s)\n", link->type, link->str);
		link = link->next;
    }
	
}