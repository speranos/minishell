#include "minishell.h"

void    ft_lexxx(char *input)
{
	t_lexer lexer;

	lexer.i = 0;
	lexer.input = input;
	lexer.c = lexer.input[lexer.i];
	while(lexer.input[lexer.i])
	{
		if(lexer.c <= 32)
			ft_skip_spaces(&lexer);
		else
			ft_searche(&lexer);
	}
	
}

void    ft_searche(t_lexer *lexer)
{   
	if(lexer->c == '|')
		ft_token(token_pipe, ft_conv_to_str(lexer->c));
	else if(lexer->c == '>' || lexer->c == '<')
		ft_redirection(lexer);
	else
		ft_token(token_string, ft_get_str(lexer));
	lexer->i++;
	lexer->c = lexer->input[lexer->i];
}