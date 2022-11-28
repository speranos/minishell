#include "../minishell.h"

void	ft_skip_space(t_lexer *lexer)
{
	// if(lexer->c <= 32)
	// {
	// 	lexer->i++;
	// 	lexer->c = lexer->input[lexer->i];
	// }
	while(lexer->input[lexer->i] <= 32 && lexer->input[lexer->i])
		lexer->i++;
	lexer->i--;
	// lexer->c = lexer->input[lexer->i];
}

char	*ft_conv_to_str(char c)
{
	char *ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = c;
	ret[1] = '\0';
	return(ret);
}