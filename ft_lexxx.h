#ifndef FT_LEXXX_H
#define FT_LEXXX_H

// typedef struct tokens
// {

// }   t_tokens;

typedef struct lexer
{
	int     i;
	char    c;
	char	*input;

}   t_lexer;


void    ft_lexxx(char *input);

#endif