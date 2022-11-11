#ifndef FT_LEXXX_H
#define FT_LEXXX_H


typedef struct lexer
{
	int     i;
	char    c;
	char	*input;

}   t_lexer;

typedef struct token
{
	enum	tokens
	{
		token_string,
		token_pipe

	}	type;
	char	*str;
}	t_token;

void   	ft_lexxx(char *input);
void	ft_token(int type, char *str);
char	*ft_conv_to_str(char c);
void	ft_skip_spaces(t_lexer *lexer);
void	ft_print(t_token token);

#endif