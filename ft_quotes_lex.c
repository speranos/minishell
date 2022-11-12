#include "minishell.h"

void	ft_syntax_error(void)
{
	printf("Syntax...error...\nExit...\n");
	exit(0);
}

void	ft_quotes_check(t_lexer *lexer)
{
	int	i;
	int	s;

	i = lexer->i;
	s = 0;
	while(lexer->input[i] > 32 && !ft_check_str(lexer->input[i]) && lexer->input)
	{
		if(lexer->input[i] == '"')
			s++;
		i++;
	}
	if(s % 2 == 0)
		return;
	ft_syntax_error();
}
// char	*ft_quotes(t_lexer *lexer)
// {
// 	int 	tmp;
// 	char	*ret;
// 	int		i;

// 	tmp = lexer->i;
// 	i = 0;
// 	ret = NULL;
// 	if(ft_check_end_quotes(lexer) == 1)
// 		ft_syntax_error();
// 	else
// 		{
// 			ret = malloc(sizeof(char) * (lexer->i - tmp) + 2);
// 			while(tmp <= lexer->i)
// 				ret[i++] = lexer->input[tmp++];
// 			ret[i] = '\0';
// 		}
// 	return(ret);
// }
