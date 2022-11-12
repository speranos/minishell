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