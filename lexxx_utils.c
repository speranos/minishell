#include "minishell.h"

void	ft_skip_spaces(t_lexer *lexer)
{
	if(lexer->c <= 32)
	{
		lexer->i++;
		lexer->c = lexer->input[lexer->i];
	}
}

char	*ft_conv_to_str(char c)
{
	char *ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = c;
	ret[1] = '\0';
	return(ret);
}

char	*ft_get_str(t_lexer *lexer)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	a = lexer->i;
	while(lexer->input[a] && ft_check_str(lexer->input[a]) != 1)
		a++;
	i = a - lexer->i;
	a = 0;
	ret = malloc(sizeof(char) * i + 1);
	while(a < i)
		ret[a++] = lexer->input[lexer->i++];
	ret[a] = '\0';
	lexer->i--;
	return(ret);
}

int	ft_check_str(char c)
{
	if(c <= 32)
		return(1);
	else if(c == '|')
		return(1);
	else if(c == '>' || c == '<')
		return(1);
	else if(c == '$' || c == '"')
		return(1);
	return(0);
}