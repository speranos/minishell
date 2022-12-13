#include "../minishell.h"

void	ft_get_len(t_lexer *lexer)
{
	while (lexer->input[lexer->len])
	{
		lexer->c = lexer->input[lexer->len];
		if (ft_check_sym(lexer->c, lexer) == 1)
			break;
		lexer->len++;
	}
}

char	*ft_get_str(t_lexer *lexer)
{
	int		i;
	char	*ret;

	i = 0;
	lexer->len = lexer->i;
	lexer->quotes = 0;
	ft_get_len(lexer);
	i = lexer->len - lexer->i;
	lexer->len = 0;
	ret = malloc(sizeof(char) * i + 1);
	while (lexer->len < i)
		ret[lexer->len++] = lexer->input[lexer->i++];
	ret[lexer->len] = '\0';
	lexer->i--;
	return (ret);
}

int	ft_check_sym(char c, t_lexer *lexer)
{
	if(c <= 32)
		return (1);
	else if(c == '|')
		return (1);
	else if(c == '>' || c == '<')
		return (1);
	else if(c == '"' || c == 39)
		ft_quotes_skip(lexer);
	return (0);
}

void	ft_quotes_skip(t_lexer *lexer)
{
	if(lexer->c == '"')
	{
		lexer->len++;
		while (lexer->input[lexer->len])
		{
			if (lexer->input[lexer->len] == '"')
				break;
			lexer->len++;
		}
		if (lexer->input[lexer->len] == '\0')
			{
				ft_syntax_error();
				lexer->quotes++;
			}
	}
	else if(lexer->c == 39)
		ft_single_quotes(lexer);
}

void	ft_single_quotes(t_lexer *lexer)
{
	lexer->len++;
	while (lexer->input[lexer->len])
	{
		if (lexer->input[lexer->len] == 39)
			break;
		lexer->len++;
	}
	if (lexer->input[lexer->len] == '\0')
		{
			ft_syntax_error();
			lexer->quotes++;
		}
}