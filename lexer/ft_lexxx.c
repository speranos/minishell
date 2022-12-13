#include "../minishell.h"

// t_parser	*create_parser(char *str, int type)
// {
// 	t_parser *parser;

// 	parser = malloc(sizeof(t_parser));
// 	parser->str = str;
// 	parser->type = type;
// 	parser->next = NULL;
// 	return (parser);
// }

// void	ft_add_back(t_parser **parser, char *str, int type)
// {
// 	t_parser *tmp1 = *parser;
// 	t_parser *tmp = create_parser(str, type);

// 	if (*parser == NULL)
// 	{
// 		*parser = tmp;
// 		return ;
// 	}
// 	while ((*parser)->next)
// 		*parser = (*parser)->next;
// 	(*parser)->next = tmp;
// 	*parser = tmp1;
// }
void	ft_free_link(t_token *link)
{
	t_token	*node;

	while (link != NULL)
	{
		node = link;
		free(link->str);
		free(node);
		link = link->next;
	}
}

void	ft_add_back(t_token **link, t_token *node)
{
	t_token	*head;

	head = *link;
	if(*link == NULL)
	{
		*link = node;
		return;
	}
	else
	{
		while((*link)->next != NULL)
			*link = (*link)->next;
		(*link)->next = node;
		*link = head;
	}
}

void    ft_lexxx(char *input)
{
	t_lexer lexer;
	t_token *node;
	t_token *link;

	link = NULL;
	lexer.i = 0;
	lexer.input = input;
	lexer.quotes = 0;
	lexer.c = lexer.input[lexer.i];
	while(lexer.input[lexer.i])
	{
		node = ft_searche(&lexer);
		ft_add_back(&link, node);
	}
	if(lexer.quotes != 0 || ft_syntax_check(link) == 1)
	{
		ft_free_link(link);
		return;
	}
	ft_expand(link);
	ft_remove_quotes(link);
	ft_rev(link);
	ft_free_link(link);
	// ft_free_parser();
	// ft_free_redi();
}

t_token	*ft_searche(t_lexer *lexer)
{
    t_token *token;

	token = NULL;
	if(lexer->c <= 32)
		ft_skip_space(lexer);
	else if(lexer->c == '|')
		token = ft_token(token_pipe, ft_conv_to_str(lexer->c));
	else if(lexer->c == '>' || lexer->c == '<')
		token = ft_redirection(lexer);
	else
		token = ft_token(token_string, ft_get_str(lexer));
	lexer->i++;
	lexer->c = lexer->input[lexer->i];
    return token;
}