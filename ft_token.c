#include "minishell.h"

void    ft_token(int type, char *str)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->type = type;
	token->str = str;
	ft_print(*token);
}

void    ft_print(t_token token)
{
	printf("token(%d, %s)\n",token.type, token.str);
}

void	ft_syntax_error(void)
{
	printf("minishell: syntax...error...\n");
}