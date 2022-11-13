#include "minishell.h"

char	*ft_get_str(t_lexer *lexer)
{
	int		i;
	char	*ret;

	i = 0;
	lexer->len = lexer->i;
	while(lexer->input[lexer->len] && ft_check_sym(lexer->input[lexer->len], lexer) != 1)
		lexer->len++;
	i = lexer->len - lexer->i;
	lexer->len = 0;
	ret = malloc(sizeof(char) * i + 1);
	while(lexer->len < i)
		ret[lexer->len++] = lexer->input[lexer->i++];
	ret[lexer->len] = '\0';
	lexer->i--;
	return(ret);
}

int	ft_check_sym(char c, t_lexer *lexer)
{
	if(c <= 32)
		return(1);
	else if(c == '|')
		return(1);
	else if(c == '>' || c == '<')
		return(1);
	else if(c == '"')
		ft_quotes_skip(lexer);
	return(0);
}

void	ft_quotes_skip(t_lexer *lexer)
{
	lexer->len++;
	while(lexer->input[lexer->len] && (lexer->input[lexer->len] != '"'))
		lexer->len++;
	if(lexer->input[lexer->len] == '\0')
		ft_syntax_error();
}