#include "minishell.h"

void    ft_redirection(t_lexer *lexer)
{
	if(lexer->c == '<')
	{
		if(lexer->input[lexer->i + 1] == '<')
			ft_app_input(lexer);
		else
			ft_red_input(lexer);
	}
	else if(lexer->c == '>')
	{
		if(lexer->input[lexer->i + 1] == '>')
			ft_app_error(lexer);
		else
			ft_red_output(lexer);
	}
}

void	ft_app_input(t_lexer *lexer)
{
	char	*ret;

	lexer->i += 2;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	ft_token(token_app_input, ret);
}

void	ft_red_input(t_lexer *lexer)
{
	char	*ret;

	lexer->i++;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	ft_token(token_red_input, ret);
}

void	ft_app_error(t_lexer *lexer)
{
	char	*ret;

	lexer->i += 2;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	ft_token(token_app_error, ret);
}

void	ft_red_output(t_lexer *lexer)
{
	char	*ret;
	
	lexer->i++;
	ft_ignore_spaces(lexer);
	ret = ft_get_str(lexer);
	ft_token(token_red_output, ret);
}

void	ft_ignore_spaces(t_lexer *lexer)
{
	while(lexer->input[lexer->i] <= 32)
		lexer->i++;
}