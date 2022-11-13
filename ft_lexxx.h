#ifndef FT_LEXXX_H
#define FT_LEXXX_H


typedef struct lexer
{
	int     i;
	char    c;
	int		len;
	char	*input;

}   t_lexer;

typedef struct token
{
	enum	tokens
	{
		token_string,
		token_pipe,
		token_red_input,
		token_red_output,
		token_app_input,
		token_app_output
	}	type;
	char	*str;
}	t_token;

void   	ft_lexxx(char *input);
void	ft_token(int type, char *str);
char	*ft_conv_to_str(char c);
void	ft_skip_spaces(t_lexer *lexer);
void	ft_print(t_token token);
int		ft_check_sym(char c, t_lexer *lexer);
char	*ft_get_str(t_lexer *lexer);
void    ft_searche(t_lexer *lexer);
void	ft_syntax_error(void);
void	ft_quotes_skip(t_lexer *lexer);
void    ft_redirection(t_lexer *lexer);

#endif