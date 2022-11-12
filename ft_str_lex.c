#include "minishell.h"

char	*ft_get_str(t_lexer *lexer)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	a = lexer->i;
	ft_quotes_check(lexer);
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
	return(0);
}
