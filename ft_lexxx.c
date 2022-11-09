#include "minishell.h"


void    ft_skip_spaces(t_lexer *lexer)
{
    if(lexer->c <= 32)
        lexer->i++;

}

void    ft_token(t_lexer *lexer)
{
    (void)lexer;
}

void    ft_lexxx(char *input)
{
    t_lexer lexer;

    lexer.i = 0;
    lexer.input = input;
    lexer.c = lexer.input[lexer.i];
    while(input[lexer.i])
    {
        ft_skip_spaces(&lexer);
        ft_token(&lexer);
        lexer.i++;
        lexer.c = lexer.input[lexer.i];
    }
    
}