#ifndef FT_LEXXX_H
#define FT_LEXXX_H

static int count;

typedef struct lexer
{
	int     i;
	char    c;
	int		len;
	char	*input;
	int		quotes;

}   t_lexer;


// typedef struct parser
// {
// 	char *str;
// 	int type;
// 	struct parser *next;
// }	t_parser;


typedef struct token
{
	enum	tokens
	{
		token_string,
		token_pipe,
		token_red_input, //<
		token_red_output, //>
		token_app_input, //<<
		token_app_error //>>
	}	type;
	char	*str;
	struct token *next;
	int		i;
	int		len;
	int		index;
}	t_token;

typedef struct redi
{
	enum
	{
		red_input, //<
		red_output, //>
		app_input, //<<
		app_error //>>
	}	type;
	char	*fname;
	struct redi *next;
}	t_redi;

typedef struct parser
{
	char	**args;
	t_redi	*redi;
	struct parser *next;
}	t_parser;

int		exit_error;
t_parser	*ft_lexxx(char *input);
t_token	*ft_token(int type, char *str);
char	*ft_conv_to_str(char c);
void	ft_skip_space(t_lexer *lexer);
int		ft_check_sym(char c, t_lexer *lexer);
char	*ft_get_str(t_lexer *lexer);
t_token	*ft_searche(t_lexer *lexer);
void	ft_syntax_error(void);
void	ft_quotes_skip(t_lexer *lexer);
t_token	*ft_redirection(t_lexer *lexer);
t_token	*ft_red_output(t_lexer *lexer);
t_token	*ft_app_error(t_lexer *lexer);
t_token	*ft_red_input(t_lexer *lexer);
t_token	*ft_app_input(t_lexer *lexer);
void	ft_ignore_spaces(t_lexer *lexer);
void	ft_single_quotes(t_lexer *lexer);
void	ft_init(t_token *link);

#endif